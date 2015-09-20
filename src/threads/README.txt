The following are the changes required to add a mega alarm test.

1. The name of the test, e.g. alarm-mega, added to Make.tests
2. The name of the test associated with the function within the tests.c file
3. The function declared within the tests.h file
4. The test_alarm_mega function itself added to alarm-wait.c. 
The function is simply a copy of test_alarm_multiple with one of the paramaters changed from 7 to 70.

