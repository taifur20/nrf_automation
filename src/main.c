/*
 * Copyright (c) 2018 Nordic Semiconductor ASA
 *
 * SPDX-License-Identifier: LicenseRef-Nordic-5-Clause
 */

#include <zephyr/types.h>
#include <stddef.h>
#include <string.h>
#include <errno.h>
#include <zephyr/sys/printk.h>
#include <zephyr/sys/byteorder.h>
#include <zephyr/kernel.h>
#include <zephyr/drivers/gpio.h>
#include <soc.h>

#include <zephyr/bluetooth/bluetooth.h>
#include <zephyr/bluetooth/hci.h>
#include <zephyr/bluetooth/conn.h>
#include <zephyr/bluetooth/uuid.h>
#include <zephyr/bluetooth/gatt.h>

#include <zephyr/settings/settings.h>
#include <dk_buttons_and_leds.h>

#include "ble_automation/automation.h"
#include "sensors/sensor.h"


#define RUN_STATUS_LED          DK_LED1
#define CON_STATUS_LED          DK_LED2
#define RUN_LED_BLINK_INTERVAL  1000

#define USER_LED                DK_LED3

/* Declarations */
void on_connected(struct bt_conn *conn, uint8_t err);
void on_disconnected(struct bt_conn *conn, uint8_t reason);
static void sensor_ccc_cfg_temperature_changed(const struct bt_gatt_attr *attr, uint16_t value);
static void sensor_ccc_cfg_humidity_changed(const struct bt_gatt_attr *attr, uint16_t value);
static void sensor_ccc_cfg_pressure_changed(const struct bt_gatt_attr *attr, uint16_t value);

struct bt_conn_cb bluetooth_callbacks = {
	.connected 		= on_connected,
	.disconnected 	= on_disconnected,
};

static void on_connected(struct bt_conn *conn, uint8_t err)
{
	if (err) {
		printk("Connection failed (err %u)\n", err);
		return;
	}

	printk("Connected\n");

	//dk_set_led_on(CON_STATUS_LED);
}

static void on_disconnected(struct bt_conn *conn, uint8_t reason)
{
	printk("Disconnected (reason %u)\n", reason);

	//dk_set_led_off(CON_STATUS_LED);
}

#ifdef CONFIG_BT_LBS_SECURITY_ENABLED
static void security_changed(struct bt_conn *conn, bt_security_t level,
			     enum bt_security_err err)
{
	char addr[BT_ADDR_LE_STR_LEN];

	bt_addr_le_to_str(bt_conn_get_dst(conn), addr, sizeof(addr));

	if (!err) {
		printk("Security changed: %s level %u\n", addr, level);
	} else {
		printk("Security failed: %s level %u err %d\n", addr, level,
			err);
	}
}
#endif

BT_CONN_CB_DEFINE(conn_callbacks) = {
#ifdef CONFIG_BT_LBS_SECURITY_ENABLED
	.security_changed = security_changed,
#endif
};

#if defined(CONFIG_BT_LBS_SECURITY_ENABLED)
static void auth_passkey_display(struct bt_conn *conn, unsigned int passkey)
{
	char addr[BT_ADDR_LE_STR_LEN];

	bt_addr_le_to_str(bt_conn_get_dst(conn), addr, sizeof(addr));

	printk("Passkey for %s: %06u\n", addr, passkey);
}

static void auth_cancel(struct bt_conn *conn)
{
	char addr[BT_ADDR_LE_STR_LEN];

	bt_addr_le_to_str(bt_conn_get_dst(conn), addr, sizeof(addr));

	printk("Pairing cancelled: %s\n", addr);
}

static void pairing_complete(struct bt_conn *conn, bool bonded)
{
	char addr[BT_ADDR_LE_STR_LEN];

	bt_addr_le_to_str(bt_conn_get_dst(conn), addr, sizeof(addr));

	printk("Pairing completed: %s, bonded: %d\n", addr, bonded);
}

static void pairing_failed(struct bt_conn *conn, enum bt_security_err reason)
{
	char addr[BT_ADDR_LE_STR_LEN];

	bt_addr_le_to_str(bt_conn_get_dst(conn), addr, sizeof(addr));

	printk("Pairing failed conn: %s, reason %d\n", addr, reason);
}

static struct bt_conn_auth_cb conn_auth_callbacks = {
	.passkey_display = auth_passkey_display,
	.cancel = auth_cancel,
};

static struct bt_conn_auth_info_cb conn_auth_info_callbacks = {
	.pairing_complete = pairing_complete,
	.pairing_failed = pairing_failed
};
#else
static struct bt_conn_auth_cb conn_auth_callbacks;
static struct bt_conn_auth_info_cb conn_auth_info_callbacks;
#endif


uint16_t temperature;
uint16_t humidity;
uint16_t pressure;

static void sensor_ccc_cfg_temperature_changed(const struct bt_gatt_attr *attr, uint16_t value)
{
	bool notify_enable_temperature = (value == BT_GATT_CCC_NOTIFY);
	LOG_INF("Notification %s", notify_enable_temperature ? "enabled" : "disabled");
}

static void sensor_ccc_cfg_humidity_changed(const struct bt_gatt_attr *attr, uint16_t value)
{
	bool notify_enable_humidity = (value == BT_GATT_CCC_NOTIFY);
	LOG_INF("Notification %s", notify_enable_humidity ? "enabled" : "disabled");
}

static void sensor_ccc_cfg_pressure_changed(const struct bt_gatt_attr *attr, uint16_t value)
{
	bool notify_enable_pressure = (value == BT_GATT_CCC_NOTIFY);
	LOG_INF("Notification %s", notify_enable_pressure ? "enabled" : "disabled");
}

BT_GATT_SERVICE_DEFINE(automation_srv,
    BT_GATT_PRIMARY_SERVICE(BT_UUID_AUTOMATION_TEMP_SERVICE),
    BT_GATT_CHARACTERISTIC(BT_UUID_AUTOMATION_TEMP_CHRC,
                    BT_GATT_CHRC_READ | BT_GATT_CHRC_NOTIFY,
                    BT_GATT_PERM_READ,
                    NULL, NULL, &temperature),
    BT_GATT_CCC(sensor_ccc_cfg_temperature_changed, BT_GATT_PERM_READ | BT_GATT_PERM_WRITE),
    BT_GATT_PRIMARY_SERVICE(BT_UUID_AUTOMATION_HUMIDITY_SERVICE),
    BT_GATT_CHARACTERISTIC(BT_UUID_AUTOMATION_HUMIDITY_CHRC,
                    BT_GATT_CHRC_READ | BT_GATT_CHRC_NOTIFY,
                    BT_GATT_PERM_READ,
                    NULL, NULL, &humidity),
    BT_GATT_CCC(sensor_ccc_cfg_humidity_changed, BT_GATT_PERM_READ | BT_GATT_PERM_WRITE),
    BT_GATT_PRIMARY_SERVICE(BT_UUID_AUTOMATION_PRESSURE_SERVICE),
    BT_GATT_CHARACTERISTIC(BT_UUID_AUTOMATION_PRESSURE_CHRC,
                    BT_GATT_CHRC_READ | BT_GATT_CHRC_NOTIFY,
                    BT_GATT_PERM_READ,
                    NULL, NULL, &pressure),
    BT_GATT_CCC(sensor_ccc_cfg_pressure_changed, BT_GATT_PERM_READ | BT_GATT_PERM_WRITE),
);

void main(void)
{
	int blink_status = 0;
	int err;

	printk("Starting Bluetooth Peripheral LBS example\n");

	err = dk_leds_init();
	if (err) {
		printk("LEDs init failed (err %d)\n", err);
		return;
	}

	err = sensor_init();
	if (err)
	{
		LOG_ERR("Failed to initialize sensor: %d", err);
	}

	if (IS_ENABLED(CONFIG_BT_LBS_SECURITY_ENABLED)) {
		err = bt_conn_auth_cb_register(&conn_auth_callbacks);
		if (err) {
			printk("Failed to register authorization callbacks.\n");
			return;
		}

		err = bt_conn_auth_info_cb_register(&conn_auth_info_callbacks);
		if (err) {
			printk("Failed to register authorization info callbacks.\n");
			return;
		}
	}

	err = bluetooth_init(&bluetooth_callbacks);
	if (err) {
		LOG_ERR("bt_enable returned %d", err);
	}

    float raw_temp, raw_humi, raw_pres;

	for (;;) {
		dk_set_led(RUN_STATUS_LED, (++blink_status) % 2);
		k_sleep(K_MSEC(RUN_LED_BLINK_INTERVAL));

        err = sensor_update_measurements();
		if (err)
		{
			LOG_ERR("Failed to update sensor");
		}
        
		sensor_get_temperature(&raw_temp);
		sensor_get_humidity(&raw_humi);
		sensor_get_pressure(&raw_pres);

		temperature = (uint16_t)(raw_temp * 100);
		LOG_INF("%d", temperature / 100);
		k_sleep(K_MSEC(5));

		humidity = (uint16_t)raw_humi;
		LOG_INF("%d", humidity);
		k_sleep(K_MSEC(5));

		pressure = (uint16_t)raw_pres;
		LOG_INF("%d", pressure);
		k_sleep(K_MSEC(5));

		err = bt_gatt_notify(NULL, &automation_srv.attrs[2],
								 &temperature, sizeof(temperature));
		if (err)
		{
			LOG_ERR("Notify error: %d", err);
		}
        k_sleep(K_MSEC(RUN_LED_BLINK_INTERVAL));

		err = bt_gatt_notify(NULL, &automation_srv.attrs[5],
								 &humidity, sizeof(humidity));
		if (err)
		{
			LOG_ERR("Notify error: %d", err);
		}
		k_sleep(K_MSEC(RUN_LED_BLINK_INTERVAL));

		err = bt_gatt_notify(NULL, &automation_srv.attrs[8],
								 &pressure, sizeof(pressure));
		if (err)
		{
			LOG_ERR("Notify error: %d", err);
		}
		k_sleep(K_MSEC(RUN_LED_BLINK_INTERVAL));

	}
}
