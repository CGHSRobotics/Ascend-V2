
#include "ace.h"

namespace ace::auton {

/* ========================================================================== */
/*                        Global Variables Definitions                        */
/* ========================================================================== */

int auton_selection_index = 0;
/* ========================================================================== */
/*                               Score Auton                                   */
/* ========================================================================== */
void score() {
    
}

/* ========================================================================== */
/*                               Contact Auton                                  */
/* ========================================================================== */
void contact() {

}

/* ========================================================================== */
/*                              Three Side Auton                              */
/* ========================================================================== */
void three_side() {
  // Dead
}

// ross is good

/* ========================================================================== */
/*                               Two Side Auton                               */
/* ========================================================================== */
void two_side() {
  // Dead
}

/* ========================================================================== */
/*                                   Skills                                   */
/* ========================================================================== */
void skills() {

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