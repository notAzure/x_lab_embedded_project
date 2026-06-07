#ifndef STEPPERMOTOR_H
#define STEPPERMOTOR_H

void steppermotorsetup();
void stepTranslate(int step);
void rotateCertainSteps(int steps, int delayTime);

#endif // STEPPERMOTOR_H
