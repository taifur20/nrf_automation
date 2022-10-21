#include <zephyr.h>
#include <logging/log.h>

#include <bluetooth/bluetooth.h>
#include <bluetooth/uuid.h>
#include <bluetooth/gatt.h>
#include <bluetooth/hci.h>

/** @brief UUID of the Automation Temperature Service. **/
#define BT_UUID_AUTOMATION_TEMP_SERV_VAL \
	BT_UUID_128_ENCODE(0xa5d1b001, 0x8fee, 0x4fba, 0x8b95, 0x77173311f460)
/** @brief UUID of the Automation Temperature Service. **/
#define BT_UUID_AUTOMATION_HUMIDITY_SERV_VAL \
	BT_UUID_128_ENCODE(0xa5d1b002, 0x8fee, 0x4fba, 0x8b95, 0x77173311f460)
/** @brief UUID of the Automation Temperature Service. **/
#define BT_UUID_AUTOMATION_PRESSURE_SERV_VAL \
	BT_UUID_128_ENCODE(0xa5d1b003, 0x8fee, 0x4fba, 0x8b95, 0x77173311f460)

/** @brief UUID of the Automation Temperature Service. **/
#define BT_UUID_AUTOMATION_TEMP_CHRC_VAL \
	BT_UUID_128_ENCODE(0xa5d1b004, 0x8fee, 0x4fba, 0x8b95, 0x77173311f460)
/** @brief UUID of the Automation Temperature Service. **/
#define BT_UUID_AUTOMATION_HUMIDITY_CHRC_VAL \
	BT_UUID_128_ENCODE(0xa5d1b005, 0x8fee, 0x4fba, 0x8b95, 0x77173311f460)
/** @brief UUID of the Automation Temperature Service. **/
#define BT_UUID_AUTOMATION_PRESSURE_CHRC_VAL \
	BT_UUID_128_ENCODE(0xa5d1b003, 0x8fee, 0x4fba, 0x8b95, 0x77173311f460)


#define BT_UUID_AUTOMATION_TEMP_SERVICE              BT_UUID_DECLARE_128(BT_UUID_AUTOMATION_TEMP_SERV_VAL)
#define BT_UUID_AUTOMATION_HUMIDITY_SERVICE          BT_UUID_DECLARE_128(BT_UUID_AUTOMATION_HUMIDITY_SERV_VAL)
#define BT_UUID_AUTOMATION_PRESSURE_SERVICE          BT_UUID_DECLARE_128(BT_UUID_AUTOMATION_PRESSURE_SERV_VAL)
#define BT_UUID_AUTOMATION_TEMP_CHRC 	        BT_UUID_DECLARE_128(BT_UUID_AUTOMATION_TEMP_CHRC_VAL)
#define BT_UUID_AUTOMATION_HUMIDITY_CHRC 	    BT_UUID_DECLARE_128(BT_UUID_AUTOMATION_HUMIDITY_CHRC_VAL)
#define BT_UUID_AUTOMATION_PRESSURE_CHRC 	    BT_UUID_DECLARE_128(BT_UUID_AUTOMATION_PRESSURE_CHRC_VAL)


int bluetooth_init(struct bt_conn_cb *bt_cb);

