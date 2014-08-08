#include <check.h>
#include <stdlib.h>

Suite *list_suite();
Suite *primp_config_suite();
Suite *primp_config_find_suite();
Suite *connection_suite();
Suite *request_suite();
Suite *resolve_suite();
Suite *response_suite();

#define ADD_SUITE(suite_func) { \
  suite = (suite_func)(); \
  suite_runner = srunner_create(suite); \
  srunner_run_all(suite_runner, CK_NORMAL); \
  failure_count += srunner_ntests_failed(suite_runner); \
  srunner_free(suite_runner); \
}

int main(int argc, char **argv) {
  int failure_count = 0;

  Suite *suite;
  SRunner *suite_runner;

  ADD_SUITE(list_suite);
  ADD_SUITE(primp_config_suite);
  ADD_SUITE(primp_config_find_suite);
  ADD_SUITE(connection_suite);
  ADD_SUITE(request_suite);
  ADD_SUITE(resolve_suite);
  ADD_SUITE(response_suite);

  return (failure_count == 0 ? EXIT_SUCCESS : EXIT_FAILURE);
}
