William Baldwin
Project 0
CIS 520 - MWF 9:30-10:20 Fall 2015

In order to incorporate the alarm-mega text (in no particular order):

- Add alarm-mega.ck to src/test/threads folder. It is based on alarm-multiple.ck, but has check_alarm (70) instead of check_alarm (7);

- To tests.h, add following line: extern test_func test_alarm_mega;

- To tests.c, add the following line to static const struct test tests[]: {"alarm-mega", test_alarm_mega},

- To alarm-wait.c, add the following function:
void
test_alarm_mega (void) 
{
  test_sleep (5, 70);
}

- Rebuild and run.
