
#include "ace.h"

namespace ace::auton {

/* ========================================================================== */
/*                        Global Variables Definitions                        */
/* ========================================================================== */

int auton_selection_index = 0;
/* ========================================================================== */
/*                               Score Auton                                   */
/* ========================================================================== */
// Score 5 triballs, full send
void score() {
  ace::intakeMotorLeft.spin_percent(-ace::INTAKE_SPEED);

  ace::intakeMotorRight.spin_percent(-ace::INTAKE_SPEED);

  drive_chassis(118, ace::AUTON_DRIVE_SPEED, true);
  // 120
  turn_chassis(130, ace::AUTON_TURN_SPEED, true);

  ace::intakeMotorLeft.spin_percent(ace::INTAKE_SPEED);

  ace::intakeMotorRight.spin_percent(ace::INTAKE_SPEED);

  ace::intakePneumatics.set_value(1);

  drive_chassis(62, ace::AUTON_DRIVE_SPEED, true);

  ace::intakePneumatics.set_value(0);

  drive_chassis(-15, ace::AUTON_DRIVE_SPEED, true);

  ace::intakeMotorLeft.spin_percent(0);

  ace::intakeMotorRight.spin_percent(0);

  ace::intakeMotorLeft.spin_percent(-ace::INTAKE_SPEED);

  ace::intakeMotorRight.spin_percent(-ace::INTAKE_SPEED);

  turn_chassis(-90, ace::AUTON_TURN_SPEED, true);
  //-90

  drive_chassis(60, ace::AUTON_DRIVE_SPEED, true);

  turn_chassis(100, ace::AUTON_TURN_SPEED, true);

  ace::intakeMotorLeft.spin_percent(ace::INTAKE_SPEED);

  ace::intakeMotorRight.spin_percent(ace::INTAKE_SPEED);
  // temp
  drive_chassis(67, ace::AUTON_DRIVE_SPEED, true);
  // 70
  // 60
  ace::intakeMotorLeft.spin_percent(0);

  ace::intakeMotorRight.spin_percent(0);
  // temp

  drive_chassis(-20, ace::AUTON_DRIVE_SPEED, true);

  turn_chassis(210, ace::AUTON_TURN_SPEED, true);

  drive_chassis(80, ace::AUTON_DRIVE_SPEED, true);

  turn_chassis(280, ace::AUTON_TURN_SPEED, true);

  ace::flapPneumatics.set_value(1);

  drive_chassis(-40, ace::AUTON_DRIVE_SPEED_SLOW, true);
  // 30

  turn_chassis(220, ace::AUTON_TURN_SPEED, true);
  // 240
  ace::flapPneumatics.set_value(0);

  // drive_chassis(-20, ace::AUTON_DRIVE_SPEED, true);

  // drive_chassis(20, ace::AUTON_DRIVE_SPEED, true);

  turn_chassis(235, ace::AUTON_TURN_SPEED, true);
  // 240, less is more left!

  drive_chassis(-40, ace::AUTON_DRIVE_SPEED, true);
  //-35

  drive_chassis(20, ace::AUTON_DRIVE_SPEED_FAST, true);
}

// touch bar ON OTHER (FAR) SIDE DON`T GET CONFUSED
void bar() {
  // 1
  ace::intakeMotorLeft.spin_percent(-ace::INTAKE_SPEED);

  ace::intakeMotorRight.spin_percent(-ace::INTAKE_SPEED);

  drive_chassis(-30, ace::AUTON_DRIVE_SPEED, true);
  //-20
  turn_chassis(-40, ace::AUTON_TURN_SPEED, true);

  ace::intakeMotorLeft.spin_percent(0);

  ace::intakeMotorRight.spin_percent(0);

  drive_chassis(-35, ace::AUTON_DRIVE_SPEED, true);

  drive_chassis(35, ace::AUTON_DRIVE_SPEED, true);

  turn_chassis(30, ace::AUTON_TURN_SPEED, true);

  // drive_chassis(81, ace::AUTON_DRIVE_SPEED, true);

  // 40

  /*
  ace::flapPneumatics.set_value(0);
  drive_chassis(-20, ace::AUTON_DRIVE_SPEED, true);
  ace::flapPneumatics.set_value(0);
  turn_chassis(190, ace::AUTON_TURN_SPEED, true);
  drive_chassis(18, ace::AUTON_DRIVE_SPEED, true);
  turn_chassis(140, ace::AUTON_TURN_SPEED, true);
  ace::intakeMotorLeft.spin_percent(ace::INTAKE_SPEED);
  drive_chassis(55, ace::AUTON_DRIVE_SPEED_FAST, true);
  ace::intakeMotorLeft.spin_percent(0);
  drive_chassis(-50, ace::AUTON_DRIVE_SPEED, true);
  turn_chassis(30, ace::AUTON_TURN_SPEED, true);
  drive_chassis(73, ace::AUTON_DRIVE_SPEED, true);
  */
}

void match() {
  ace::intakeMotorLeft.spin_percent(-ace::INTAKE_SPEED);

  drive_chassis(118, ace::AUTON_DRIVE_SPEED, true);
  // 120
  turn_chassis(130, ace::AUTON_TURN_SPEED, true);

  ace::intakeMotorLeft.spin_percent(ace::INTAKE_SPEED);

  ace::intakePneumatics.set_value(1);

  drive_chassis(62, ace::AUTON_DRIVE_SPEED, true);

  ace::intakeMotorLeft.spin_percent(0);

  ace::intakePneumatics.set_value(0);

  drive_chassis(-15, ace::AUTON_DRIVE_SPEED, true);

  ace::intakeMotorLeft.spin_percent(-ace::INTAKE_SPEED);

  turn_chassis(-90, ace::AUTON_TURN_SPEED, true);
  //-90

  drive_chassis(60, ace::AUTON_DRIVE_SPEED, true);

  turn_chassis(100, ace::AUTON_TURN_SPEED, true);

  ace::intakeMotorLeft.spin_percent(ace::INTAKE_SPEED);
  // temp
  drive_chassis(67, ace::AUTON_DRIVE_SPEED, true);
  // 70
  // 60
  ace::intakeMotorLeft.spin_percent(0);
  // temp

  drive_chassis(-20, ace::AUTON_DRIVE_SPEED, true);

  turn_chassis(210, ace::AUTON_TURN_SPEED, true);

  drive_chassis(80, ace::AUTON_DRIVE_SPEED, true);

  turn_chassis(280, ace::AUTON_TURN_SPEED, true);

  ace::flapPneumatics.set_value(1);

  drive_chassis(-40, ace::AUTON_DRIVE_SPEED_SLOW, true);
  // 30

  turn_chassis(220, ace::AUTON_TURN_SPEED, true);
  // 240
  ace::flapPneumatics.set_value(0);

  // drive_chassis(-20, ace::AUTON_DRIVE_SPEED, true);

  // drive_chassis(20, ace::AUTON_DRIVE_SPEED, true);

  turn_chassis(235, ace::AUTON_TURN_SPEED, true);
  // 240, less is more left!

  drive_chassis(-35, ace::AUTON_DRIVE_SPEED, true);
  //-35

  drive_chassis(20, ace::AUTON_DRIVE_SPEED_FAST, true);
}
// scores and touches bar close side
void contact_match() {
  ace::intakeMotorLeft.spin_percent(-100);

  ace::intakeMotorRight.spin_percent(-100);

  pros::delay(4000);

  ace::intakeMotorLeft.spin_percent(0);

  ace::intakeMotorRight.spin_percent(0);

  drive_chassis(30, ace::AUTON_DRIVE_SPEED, true);

  ace::flapPneumatics.set_value(1);

  drive_chassis(-30, ace::AUTON_DRIVE_SPEED, true);

  turn_chassis(-210, ace::AUTON_TURN_SPEED, true);

  ace::flapPneumatics.set_value(0);

  drive_chassis(77, ace::AUTON_DRIVE_SPEED, true);

  ace::intakeMotorLeft.spin_percent(ace::INTAKE_SPEED);

  ace::intakeMotorRight.spin_percent(ace::INTAKE_SPEED);
  /*
  ace::intakeMotorLeft.spin_percent(-ace::INTAKE_SPEED);

  pros::delay(500);

  ace::intakeMotorLeft.spin_percent(ace::INTAKE_SPEED);

  drive_chassis(-30, ace::AUTON_DRIVE_SPEED, true);

  turn_chassis(40, ace::AUTON_TURN_SPEED, true);
*/
  // ace::intakeMotorLeft.spin_percent(ace::launch_speed);

  // drive_chassis(-30, ace::AUTON_DRIVE_SPEED, true);
  // 30
  //  ace::intakeMotorLeft.spin_percent(0);

  // drive_chassis(37, ace::AUTON_DRIVE_SPEED, true);
  //-35

  /*
    ace::intakeMotorLeft.spin_percent(0);

    ace::flapPneumatics.set_value(1);

    turn_chassis(5, ace::AUTON_TURN_SPEED, true);

    drive_chassis(40, ace::AUTON_DRIVE_SPEED, true);

    ace::flapPneumatics.set_value(0);

    turn_chassis(-210, ace::AUTON_TURN_SPEED, true);

    ace::intakeMotorLeft.spin_percent(ace::launch_speed);

    drive_chassis(55, ace::AUTON_DRIVE_SPEED, true);
    */
  // 58
}
// go touch bar on CLOSE SIDE, distance at end little whack
// RISKY DRIVES OUT INTO CENTER 110
void contact() {
  ace::intakeMotorLeft.spin_percent(ace::INTAKE_SPEED);

  ace::intakeMotorRight.spin_percent(ace::INTAKE_SPEED);

  pros::delay(500);

  ace::intakeMotorLeft.spin_percent(-ace::INTAKE_SPEED);

  ace::intakeMotorRight.spin_percent(-ace::INTAKE_SPEED);

  drive_chassis(110, ace::AUTON_DRIVE_SPEED_SLOW, true);

  drive_chassis(-105, ace::AUTON_DRIVE_SPEED_SLOW, true);

  flapPneumatics.set_value(1);

  turn_chassis(-90, ace::AUTON_TURN_SPEED, true);

  drive_chassis(-10, ace::AUTON_DRIVE_SPEED_SLOW, true);

  turn_chassis(-120, ace::AUTON_TURN_SPEED, true);

  flapPneumatics.set_value(0);

  drive_chassis(-10, ace::AUTON_DRIVE_SPEED_SLOW, true);

  turn_chassis(-290, ace::AUTON_TURN_SPEED, true);
  //-300
  //-295

  ace::intakeMotorLeft.spin_percent(ace::launch_speed);

  ace::intakeMotorRight.spin_percent(ace::launch_speed);

  drive_chassis(61, ace::AUTON_DRIVE_SPEED_SLOW, true);
  // 55
}

// FOR EMPIRE!!!!!
void kamikaze() {
  ace::intakeMotorLeft.spin_percent(ace::launch_speed);

  ace::intakeMotorRight.spin_percent(ace::launch_speed);

  drive_chassis(110, ace::AUTON_DRIVE_SPEED_SLOW, true);
}

/* ========================================================================== */
/*                                   Skills                                   */
/* ========================================================================== */

void skills() {
  drive_chassis(30, ace::AUTON_DRIVE_SPEED, true);

  turn_chassis(40, ace::AUTON_TURN_SPEED, true);

  ace::intakeMotorLeft.spin_percent(ace::launch_speed);

  drive_chassis(40, ace::AUTON_DRIVE_SPEED, true);

  ace::intakeMotorLeft.spin_percent(0);

  drive_chassis(-35, ace::AUTON_DRIVE_SPEED, true);

  turn_chassis(-63, ace::AUTON_TURN_SPEED, true);
  //-57
  drive_chassis(6, ace::AUTON_DRIVE_SPEED, true);
  // 5
  ace::launcherMotor.move_voltage(LAUNCH_SPEED * 120);
  //.launch_auton(ace::launch_speed);

  pros::delay(27000);  // 27
  ace::launcherMotor.move_voltage(0);
  ace::launcherMotor.set_brake_mode(MOTOR_BRAKE_HOLD);
  ace::launcherMotor.brake();

  drive_chassis(-5, ace::AUTON_DRIVE_SPEED, true);
  // flag
  turn_chassis(-190, ace::AUTON_TURN_SPEED, true);
  // 200

  // ace::intakePneumatics.set_value(1);

  drive_chassis(50, ace::AUTON_DRIVE_SPEED, true);

  turn_chassis(-225, ace::AUTON_TURN_SPEED, true);

  ace::intakeMotorLeft.move_voltage(80 * 120);

  drive_chassis(135, ace::AUTON_DRIVE_SPEED_FAST, true);
  // above drive to other side

  turn_chassis(-265, ace::AUTON_TURN_SPEED, true);

  drive_chassis(30, ace::AUTON_DRIVE_SPEED_FAST, true);

  turn_chassis(-295, ace::AUTON_TURN_SPEED, true);

  drive_chassis(40, ace::AUTON_DRIVE_SPEED_FAST, true);

  drive_chassis(-35, ace::AUTON_DRIVE_SPEED_FAST, true);

  // turn_chassis(-270, ace::AUTON_DRIVE_SPEED, true);

  // drive_chassis(90, ace::AUTON_DRIVE_SPEED, true);

  turn_chassis(-365, ace::AUTON_DRIVE_SPEED, true);

  ace::intakeMotorLeft.move_voltage(0);

  drive_chassis(75, ace::AUTON_DRIVE_SPEED_FAST, true);

  turn_chassis(-440, ace::AUTON_DRIVE_SPEED, true);

  ace::flapPneumatics.set_value(1);

  drive_chassis(-75, ace::AUTON_DRIVE_SPEED_FAST, true);

  drive_chassis(70, ace::AUTON_DRIVE_SPEED_FAST, true);

  ace::flapPneumatics.set_value(0);

  turn_chassis(-490, ace::AUTON_DRIVE_SPEED, true);

  drive_chassis(-110, ace::AUTON_DRIVE_SPEED_FAST, true);

  turn_chassis(-365, ace::AUTON_DRIVE_SPEED, true);
  //-370

  ace::flapPneumatics.set_value(1);

  drive_chassis(-90, ace::AUTON_DRIVE_SPEED_FAST, true);

  drive_chassis(50, ace::AUTON_DRIVE_SPEED_FAST, true);
}
void cool_skills() {
  turn_chassis(-190, ace::AUTON_TURN_SPEED, true);
  // 200

  // ace::intakePneumatics.set_value(1);

  drive_chassis(50, ace::AUTON_DRIVE_SPEED, true);

  turn_chassis(-225, ace::AUTON_TURN_SPEED, true);

  ace::intakeMotorLeft.move_voltage(80 * 120);

  drive_chassis(135, ace::AUTON_DRIVE_SPEED, true);

  turn_chassis(-340, ace::AUTON_DRIVE_SPEED, true);

  drive_chassis(90, ace::AUTON_DRIVE_SPEED, true);

  ace::intakeMotorLeft.move_voltage(0);

  turn_chassis(-420, ace::AUTON_DRIVE_SPEED, true);

  ace::flapPneumatics.set_value(1);

  drive_chassis(-45, ace::AUTON_DRIVE_SPEED, true);

  drive_chassis(40, ace::AUTON_DRIVE_SPEED, true);

  ace::flapPneumatics.set_value(0);

  turn_chassis(-440, ace::AUTON_DRIVE_SPEED, true);

  drive_chassis(-60, ace::AUTON_DRIVE_SPEED, true);

  turn_chassis(-495, ace::AUTON_DRIVE_SPEED, true);

  drive_chassis(-60, ace::AUTON_DRIVE_SPEED, true);

  turn_chassis(-365, ace::AUTON_DRIVE_SPEED, true);
  //-340

  ace::flapPneumatics.set_value(1);

  drive_chassis(-70, ace::AUTON_DRIVE_SPEED, true);

  // drive to other side

  // ace::intakePneumatics.set_value(0);

  /*
    turn_chassis(90, ace::AUTON_TURN_SPEED, true);
    // 90
    //  ace::intakePneumatics.set_value(0);

    // 30
    drive_chassis(40, ace::AUTON_DRIVE_SPEED, true);

    ace::intakeMotorLeft.move_voltage(90);

    drive_chassis(-40, ace::AUTON_DRIVE_SPEED, true);

    turn_chassis(80, ace::AUTON_DRIVE_SPEED, true);

    drive_chassis(55, ace::AUTON_DRIVE_SPEED, true);
    // drive_chassis(-30, ace::AUTON_DRIVE_SPEED, true);
    //  resume run second back out

    turn_chassis(-29, ace::AUTON_TURN_SPEED, true);

    drive_chassis(75, ace::AUTON_DRIVE_SPEED, true);
    // 55

    turn_chassis(45, ace::AUTON_TURN_SPEED, true);

    drive_chassis(50, ace::AUTON_DRIVE_SPEED, true);

    turn_chassis(130, ace::AUTON_TURN_SPEED, true);

    ace::flapPneumatics.set_value(1);

    ace::intakeMotorLeft.move_voltage(80 * 120);

    drive_chassis(55, ace::AUTON_DRIVE_SPEED, true);

    ace::intakeMotorLeft.move_voltage(0);

    drive_chassis(-10, ace::AUTON_DRIVE_SPEED, true);

    ace::flapPneumatics.set_value(0);

    turn_chassis(45, ace::AUTON_TURN_SPEED, true);
    // 95
    drive_chassis(100, ace::AUTON_DRIVE_SPEED, true);

    turn_chassis(185, ace::AUTON_TURN_SPEED, true);

    drive_chassis(55, ace::AUTON_DRIVE_SPEED, true);

    drive_chassis(-10, ace::AUTON_DRIVE_SPEED, true);
    */
}
/* ========================================================================== */
/*                         Auton Function Definitions                         */
/* ========================================================================== */

/* ------------------------------ Auton Page Up ----------------------------- */
void auton_page_up() {
  auton_selection_index += 1;
  if (auton_selection_index > auton_selection.size() - 1) {
    auton_selection_index = 0;
  }
}

/* ----------------------------- Auton Page Down ---------------------------- */
void auton_page_down() {
  auton_selection_index -= 1;
  if (auton_selection_index < 0) {
  }
  auton_selection_index = auton_selection.size() - 1;
}

/* ------------------------------ Roller Auton ------------------------------ */
/*
void roller_auton(float rollerDegrees) {

  float actual_degrees = rollerDegrees * 3.0;
  //Untested, previously only for 1 motor
  intakeMotorLeft.move_relative(actual_degrees, 100);
  intakeMotorRight.move_relative(actual_degrees, 100);
  while (intakeMotorLeft.is_stopped() == 0)
  {
    pros::delay(ez::util::DELAY_TIME);
  }
}
*/

/* --------------------------- Drive Chassis Auton -------------------------- */
void drive_chassis(float distance, float speed, bool wait) {
  bool slew_enabled = distance >= 14;
  chassis.set_drive_pid(distance, speed, slew_enabled);
  if (wait) {
    chassis.wait_drive();
  }
}

/* --------------------------- Turn Chassis Auton --------------------------- */
void turn_chassis(float angle, float speed, bool wait) {
  chassis.set_turn_pid(angle, speed);
  if (wait) {
    chassis.wait_drive();
  }
}

/* ------------------------------ Launch Auton ------------------------------ */

void launch_auton(float speed) {
  ace::launch(speed);
}

/* ------------------------------ Endgame Auton ----------------------------- */
void endgame_auton() {
}

void auton_intake_reverse(float time, float speed) {
  ace::intakeMotorLeft.spin_percent(speed);
  pros::delay(time);
  ace::intakeMotorLeft.spin_percent(0);
}
}  // namespace ace::auton