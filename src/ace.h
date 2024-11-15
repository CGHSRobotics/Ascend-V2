
#ifndef ACE_CGHS
#define ACE_CGHS

#include "main.h"

using std::string;

extern pros::Controller partner;

/* ========================================================================== */
/*                             Ace Util Namespace                             */
/* ========================================================================== */
namespace ace::util {

/* ========================================================================== */
/*                            Function Declarations                           */
/* ========================================================================== */

/* -------------------------- Celsius To Farenheit -------------------------- */
static float cel_to_faren(float celsius) {
  return (float)((celsius * 9.0 / 5.0) + 32.0);
}

/* -------------------------- Farenheit To Celsius -------------------------- */
static float faren_to_cel(float farenheit) {
  return (float)((farenheit - 32.0) * 5.0 / 9.0);
}

/* ----------------------------- Bool To String ----------------------------- */
static std::string bool_to_str(bool input) {
  if (input)
    return "y";
  else
    return "n";
}

/* ------------------------------- Timer Class ------------------------------ */
class timer {
 public:
  float maxTime = 0;
  float currTime = 0;

  timer(float max_time) {
    maxTime = max_time;
    currTime = 0;
  }

  void update(float updateTime) {
    currTime += updateTime;
  }

  bool done() {
    return currTime >= maxTime;
  }

  void reset() {
    currTime = 0;
  }
};
}  // namespace ace::util

/* ========================================================================== */
/*                             Main Ace Namespace                             */
/* ========================================================================== */
namespace ace {

/* ========================================================================== */
/*                                Device Ports                                */
/* ========================================================================== */

/* --------------------------------- Chassis -------------------------------- */
#define PORT_CHASSIS_L_F -10
#define PORT_CHASSIS_L_C -8
// dead
#define PORT_CHASSIS_L_B 9

#define PORT_CHASSIS_R_F 19
#define PORT_CHASSIS_R_C 20
// dead
#define PORT_CHASSIS_R_B -18

/* ------------------------- Other Motors / Devices ------------------------- */
#define PORT_INTAKE_LEFT -16
#define PORT_INTAKE_RIGHT -6

#define PORT_CHAIN -5
// dead
#define PORT_LAUNCHER 21
#define PORT_ENDGAME_LEFT 11
#define PORT_ENDGAME_RIGHT 3
// dead
#define PORT_VISION 2
// dead
#define PORT_IMU 7
#define PORT_ROTATION 1
// dead

/* ------------------------------- ADI Devices ------------------------------ */

#define PORT_PNEU_ENDGAME \
  {INTERNAL_ADI_PORT, 'E'}
// edngame
#define PORT_PNEU_INTAKE \
  {INTERNAL_ADI_PORT, 'H'}
// back flaps

#define PORT_PNEU_LIFT_1 \
  {INTERNAL_ADI_PORT, 'F'}
// pto
#define PORT_PNEU_LIFT_2 \
  {INTERNAL_ADI_PORT, 'D'}
// dead
#define PORT_PNEU_FLAP \
  {INTERNAL_ADI_PORT, 'G'}
// front flaps
#define PORT_SENSOR_LIGHT \
  {INTERNAL_ADI_PORT, 'A'}
// dead
#define PORT_LED \
  {INTERNAL_ADI_PORT, 'B'}
// dead
#define PORT_LIMIT \
  {INTERNAL_ADI_PORT, 'C'}
// dead

// f is endgame
/* ========================================================================== */
/*                              Global Variables                              */
/* ========================================================================== */

/* ------------------------------ Miscellaneous ----------------------------- */

// Controller type enum
enum cntr_t {
  cntr_master = 1,
  cntr_partner = 2,
  cntr_both = 3
};
// bool whether
extern bool partner_connected;
static std::vector<std::string> cntr_master_text_arr = {"", "", "", ""};
static std::vector<std::string> cntr_partner_text_arr = {"", "", "", ""};

extern std::string cntr_haptic_text;
extern bool new_haptic_request;
extern bool new_haptic_request_is_master;

extern util::timer endgame_timer;
extern util::timer reverse_endgame_timer;
extern util::timer intake_timer;
extern util::timer launcher_timer;
extern util::timer long_launch_timer;

extern double theta;
const float auto_target_angle_adjustment = 5;

const double rad2 = 1.4142;

extern int ambient_light;

/* ------------------------------ LED Variables ----------------------------- */

// enum of possible states
enum led_state_t {

  led_idle = 1,
  led_intake = 2,
  led_launch = 3
};

// current led state
// extern led_state_t curr_led_state;

// color for red alliance
const int led_color_red = 0xaa0000;
const int led_color_red_bright = 0xff0000;
// color for blue alliance
const int led_color_blue = 0x0000aa;
const int led_color_blue_bright = 0x0000ff;

/* ----------------------- User Control Enabled Bools ----------------------- */
static bool both_enabled = false;
static bool both_reverse_enabled = false;
static bool launcher_standby_enabled = false;
static bool intake_enabled = false;
static bool chain_enabled = false;
static bool intake_reverse_enabled = false;
// static bool launch_short_enabled = false;
// static bool launch_long_enabled = false;
static bool launch_enabled = false;
static bool auto_targeting_enabled = false;
static bool flap_enabled = false;
static bool lift_enabled = false;
static bool endgame_enabled = false;
static bool intake_pneu_enabled = false;
extern bool is_red_alliance;
extern bool reverse_launch_enabled;
static bool reverse_endgame_perm_enabled = false;
extern float launch_speed;
static bool launch_speed_toggle_enabled = false;

/* ------------------------------- SPEEEEEEED ------------------------------- */

// Misc Speeds
const float ROLLER_SPEED = 100.0;
const float INTAKE_SPEED = 100.0;
const float CHAIN_SPEED = 95.0;
const float AUTON_INTAKE_SPEED = 50.0;

// Launcher Speeds
const float ENDGAME_SPEED = 50.0;
const float LAUNCH_SPEED = 150.0;
const float LAUNCH_SPEED_LONG = 80;

const float LAUNCH_SPEED_STANDBY = LAUNCH_SPEED;
const float LAUNCHER_SPEED_CUTOFF = 5;

// Chassis Speeds ( * 1.27 to fit in range of [-127, 127])
const float DRIVE_SPEED = 87.0 * 1.27;  // 87
// blowed up???
const float AUTON_DRIVE_SPEED = -91.0 * 1.27;  // 87

const float AUTON_DRIVE_SPEED_FAST = -95.0 * 1.27;  // 87

const float AUTON_DRIVE_SPEED_SLOW = 60.0 * 1.27;
// 25
//  20
const float TURN_SPEED = 95.0 * 1.27;  // 71
// 87
const float AUTON_TURN_SPEED = 85.0 * 1.27;  // 87
const float TURN_SPEED_SLOW = 45.0 * 1.27;
extern bool curr_launching;

/* --------------------------- Custom Motor Class --------------------------- */
class A_Motor : public pros::Motor {
 public:
  using Motor::Motor;
  bool has_init = false;

  void init();
  float get_temp();
  void spin_percent(float percent);
  float get_percent_velocity();
  float get_percent_torque();
};

/* --------------------------- Custom Button Class -------------------------- */
class Btn_Digi {
 public:
  pros::controller_digital_e_t btn_master;
  pros::controller_digital_e_t btn_partner;
  cntr_t mode;

  // Constructor with one btn
  Btn_Digi(pros::controller_digital_e_t btn_assign, cntr_t is_master);
  // get whether button pressed
  bool get_press();
  // get whether new button press
  bool get_press_new();
};

/* ========================================================================== */
/*                      Device Declaration / Definitions                      */
/* ========================================================================== */

/* ------------------------- Other Motors / Devices ------------------------- */

static pros::Rotation rotate(PORT_ROTATION);
// Launcher motor
extern A_Motor launcherMotor;

extern A_Motor chainMotor;

// Motor for intake left
extern A_Motor intakeMotorLeft;

// Motor for intake right
extern A_Motor intakeMotorRight;

extern A_Motor endgameMotorLeft;

extern A_Motor endgameMotorRight;

// Vision sensor
const pros::Vision visionSensor(PORT_VISION, pros::E_VISION_ZERO_CENTER);

// IMU Sensor
const pros::IMU imuSensor(PORT_IMU);

// Flap Pneumatics
const pros::ADIDigitalOut flapPneumatics(PORT_PNEU_FLAP, false);

const pros::ADIDigitalOut liftPneumaticsone(PORT_PNEU_LIFT_1, false);

const pros::ADIDigitalOut liftPneumaticstwo(PORT_PNEU_LIFT_2, false);

const pros::ADIDigitalOut endgamePneumatics(PORT_PNEU_ENDGAME, false);

const pros::ADIDigitalOut intakePneumatics(PORT_PNEU_INTAKE, false);

const pros::ADIDigitalIn limit(PORT_LIMIT);

// Light Sensor for disk launching
const pros::ADILightSensor lightSensor(PORT_SENSOR_LIGHT);

extern pros::ADILed led;

/* ========================================================================== */
/*                                   Buttons                                  */
/* ========================================================================== */

/* --------------------------------- Master --------------------------------- */

static Btn_Digi btn_launch_speed_toggle(pros::E_CONTROLLER_DIGITAL_DOWN, cntr_partner);
// dead
static Btn_Digi btn_long_launch(pros::E_CONTROLLER_DIGITAL_DOWN, cntr_master);
// dead
static Btn_Digi btn_intake_pneu(pros::E_CONTROLLER_DIGITAL_A, cntr_master);

static Btn_Digi btn_endgame(pros::E_CONTROLLER_DIGITAL_UP, cntr_master);

static Btn_Digi btn_both(pros::E_CONTROLLER_DIGITAL_L1, cntr_master);

static Btn_Digi btn_reverse_both(pros::E_CONTROLLER_DIGITAL_L2, cntr_master);
// Custom Button for Intake Reverse

// Custom Button for Launch
static Btn_Digi btn_launch(pros::E_CONTROLLER_DIGITAL_X, cntr_master);
// used to be r2
static Btn_Digi btn_reverse_launch(pros::E_CONTROLLER_DIGITAL_R2, cntr_master);

// Custom Button for Flapjack Toggle
static Btn_Digi btn_flap(pros::E_CONTROLLER_DIGITAL_B, cntr_master);

static Btn_Digi btn_lift(pros::E_CONTROLLER_DIGITAL_DOWN, cntr_master);

static Btn_Digi btn_auton(pros::E_CONTROLLER_DIGITAL_RIGHT, cntr_master);

// dead
/* ---------------------------------- Both ---------------------------------- */

// Custom Button for Standby
static Btn_Digi btn_standby(pros::E_CONTROLLER_DIGITAL_UP, cntr_partner);

// Custom Button to engage Auto Targetting and grab nearest Triball
static Btn_Digi btn_auto_targeting(pros::E_CONTROLLER_DIGITAL_LEFT, cntr_partner);

// Custom Button to engage Auto Targetting
// static Bstn_Digi btn_flap(pros::E_CONTROLLER_DIGITAL_Y, cntr_both); //Ross wants it B on partner, fix later

/* --------------------------------- Partner -------------------------------- */

static Btn_Digi btn_reverse_endgame(pros::E_CONTROLLER_DIGITAL_LEFT, cntr_master);

static Btn_Digi btn_reverse_endgame_perm(pros::E_CONTROLLER_DIGITAL_B, cntr_partner);
// Custom Button to Cycle Auton

// Custom Button to switch alliance
static Btn_Digi btn_alliance(pros::E_CONTROLLER_DIGITAL_A, cntr_partner);

// Custom Button that sets launch speed to short launch constant
static Btn_Digi btn_launch_speed_short(pros::E_CONTROLLER_DIGITAL_L1, cntr_partner);

// Custom Button that sets launch speed to long launch constant
static Btn_Digi btn_launch_speed_long(pros::E_CONTROLLER_DIGITAL_L2, cntr_partner);

// Custom Button to lower short launch speed
static Btn_Digi btn_launch_speed_increase(pros::E_CONTROLLER_DIGITAL_R1, cntr_partner);

// Custom Button to lower short launch speed
static Btn_Digi btn_launch_speed_decrease(pros::E_CONTROLLER_DIGITAL_R2, cntr_partner);

/* ========================================================================== */
/*                            Function Declarations                           */
/* ========================================================================== */

/* --------------------------------- Standby -------------------------------- */
extern void both(bool enabled);

extern void reverse_both();

extern void intake_pneu_auton();

extern void launch_speed_toggle(bool enabled);

extern void endgame(float speed);

extern void reverse_endgame(float speed);

extern void reverse_endgame_perm(bool enabled);

extern void reverse_launch(float speed);
/**
 * @brief 	runs intake forward
 *
 */

/**
 * @brief	launch function, called once per frame
 *
 * @param speed		speed at which to launch disks
 * @param isLong	bool whether is long launch or not
 */
extern void launch(float speed);

/**
 * @brief	launch standby, sets speed / enabled once per frame
 *
 * @param enabled	bool whether enabled
 * @param speed		speed % on how fast standby is
 */

extern void launch_long(float speed);

extern void long_launch(float speed);

extern void reset_launcher(float speed);

extern void launch_standby(bool enabled, float speed);

extern void flap_toggle(bool enabled);

extern void lift_toggle(bool enabled);

extern void intake_pneu_toggle(bool enabled);

/**
 * @brief 	calls flapjack toggle
 *
 */

extern void endgame_toggle(bool enabled);

/**
 * @brief 	calls endgame toggle in skills for auton
 *
 */
extern void endgame_auton();

/**
 * @brief 	calls endgame toggle in skills for auton
 *
 */
extern void intake_pneu_auton();

extern void cata_toggle(bool enabled);

/**
 * @brief 	resets motors when called
 *
 */
extern void reset_motors();

extern void launch_reverse(float speed);

/* ------------------------------ Vision Sensor ----------------------------- */

/**
 * @brief
 *
 * @param enabled 	bool whether to actually move robot or not; in either case will still do theta calculations
 * @return true
 * @return false
 */
extern void auto_target(bool enabled);

/* ------------------------------ Light Sensor ------------------------------ */

extern bool light_sensor_detect();

/* ========================================================================== */
/*                           Controller Screen Task                           */
/* ========================================================================== */

/**
 * @brief	updates controller text buffers at given row
 *
 * @param cntr	controller to display on, from cntr_t enum
 * @param row	row (0-2) at which to draw text
 * @param text	std::string text that wants to be drawn
 */
extern void update_cntr_text(cntr_t cntr, u_int8_t row, std::string text);

/**
 * @brief takes in new haptic text to be rumbled on next frame
 *
 * @param new_haptic the haptic text ("-", ".") to rumble. see controller.rumble()
 */
extern void update_cntr_haptic(std::string new_haptic, bool is_master = true);

/**
 * @brief	compiles controller string arrays into a single string separated by newline; mainly for internal use
 *
 * @param arr	array to compile
 * @return		string in stated format
 */
extern std::string cntr_compile_string(std::vector<std::string> arr);

/**
 * @brief	function that runs every 50ms and updates controller screen
 *
 */
extern void update_cntr_task();

// init bool
extern bool cntr_task_init;

// Actual pros::Task for controller update screen function
static pros::Task __task_update_cntr_task(update_cntr_task, "cntr_update");

/* ========================================================================== */
/*                                Update LED's                                */
/* ========================================================================== */

/**
 * @brief	function that runs every 10ms and updates leds screen
 *
 */
// extern void update_leds_task();

// init bool
// extern bool led_task_init;

// Actual pros::Task for controller update screen function
// static pros::Task __task_update_leds_task(update_leds_task, "leds_update");
}  // namespace ace

/* ========================================================================== */
/*                             Ace Auton Namepace                             */
/* ========================================================================== */
namespace ace::auton {

/* ------------------------------- Autonomous ------------------------------- */

static std::vector<std::string> auton_selection = {
    "skills", "score", "contact"};
extern int auton_selection_index;

extern void test();
extern void red_front();
extern void blue_back();
extern void blue_front();
extern void red_front();
extern void three_side();
extern void two_side();
extern void bar();
extern void skills();
extern void score();
extern void score_match();
extern void contact();
extern void contact_match();
extern void cool_skills();
extern void kamikaze();

/**
 * @brief 	pages up auton control int by one
 *
 */
extern void auton_page_up();

/**
 * @brief 	pages down auton control int by one
 *
 */
extern void auton_page_down();

/**
 * @brief 	spins roller by x relative degrees; autonomously
 *
 * @param rollerDegrees degrees to spin by
 */

extern void launch_auton(float speed);

extern void drive_chassis(float distance, float speed, bool wait);

extern void turn_chassis(float distance, float speed, bool wait);

extern void endgame_auton();

extern void auton_intake_reverse(float time, float speed);

}  // namespace ace::auton

/* ========================================================================== */
/*                            Ace Launch Namespace                            */
/* ========================================================================== */

#endif