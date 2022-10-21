#include "automation.h"

#define LOG_MODULE_NAME automation
LOG_MODULE_REGISTER(LOG_MODULE_NAME);
#define DEVICE_NAME CONFIG_BT_DEVICE_NAME
#define DEVICE_NAME_LEN (sizeof(DEVICE_NAME)-1)


static K_SEM_DEFINE(bt_init_ok, 1, 1);

static const struct bt_data ad[] = {
    BT_DATA_BYTES(BT_DATA_FLAGS, (BT_LE_AD_GENERAL | BT_LE_AD_NO_BREDR)),
    BT_DATA(BT_DATA_NAME_COMPLETE, DEVICE_NAME, DEVICE_NAME_LEN)
};

static const struct bt_data sd[] = {
    BT_DATA_BYTES(BT_DATA_UUID128_ALL, BT_UUID_AUTOMATION_TEMP_SERV_VAL, BT_UUID_AUTOMATION_HUMIDITY_SERV_VAL, BT_UUID_AUTOMATION_PRESSURE_SERV_VAL),
};

/*
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

*/


void bt_ready(int err)
{
    if (err) {
        LOG_ERR("bt_ready returned %d", err);
    }
    k_sem_give(&bt_init_ok);
}

int bluetooth_init(struct bt_conn_cb *bt_cb)
{
    int err;
    LOG_INF("Initializing bluetooth...");

    err = bt_enable(bt_ready);
    if (err) {
        LOG_ERR("bt_enable returned %d", err);
        return err;
    }
    
    k_sem_take(&bt_init_ok, K_FOREVER);

    err = bt_le_adv_start(BT_LE_ADV_CONN, ad, ARRAY_SIZE(ad), sd, ARRAY_SIZE(sd));
    if (err) {
        LOG_ERR("Couldn't start advertising (err = %d)", err);
        return err;
    }

    return err;
}
