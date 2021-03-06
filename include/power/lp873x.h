#define	LP8732		0x0
#define LP8733		0x1

#define LP873X_LDO_NUM		2
#define LP873X_BUCK_NUM		2

/* Drivers name */
#define LP873X_LDO_DRIVER	"lp873x_ldo"
#define LP873X_BUCK_DRIVER	"lp873x_buck"

#define LP873X_BUCK_VOLT_MASK		0xFF
#define LP873X_BUCK_VOLT_MAX_HEX	0xFF
#define LP873X_BUCK_VOLT_MAX		3360000
#define LP873X_BUCK_MODE_MASK		0x1

#define LP873X_LDO_VOLT_MASK    0x1F
#define LP873X_LDO_VOLT_MAX_HEX 0x19
#define LP873X_LDO_VOLT_MAX     3300000
#define LP873X_LDO_MODE_MASK	0x1
