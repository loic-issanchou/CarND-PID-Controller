#include "PID.h"

using namespace std;

/*
* TODO: Complete the PID class.
*/

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp_ini, double Ki_ini, double Kd_ini) {

  p_error = 0.0;
  i_error = 0.0;
  d_error = 0.0;

  Kp = Kp_ini;
  Ki = Ki_ini;
  Kd = Kd_ini;

  cte = 0.0;
  cte_prev = 0.0;
  cte_sum = 0.0;
}

void PID::UpdateError(double cte) {

  double diff_cte = cte - cte_prev;
  cte_prev = cte;
  cte_sum += cte;

  p_error = Kp * cte;
  i_error = Ki * cte_sum;
  d_error = Kd * diff_cte;
}

double PID::TotalError() {

  return p_error + i_error + d_error;
}

