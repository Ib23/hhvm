<?hh
// Copyright 2004-present Facebook. All Rights Reserved.

function custom_handler($error, $errmsg, $errfile, $errline, $errcontext) {
  $file = substr(strrchr($errfile, '/'), 1);
  echo "$errmsg in $file at line $errline\n";
}
set_error_handler('custom_handler');

function test_getargs_dyncall_impl($a, $b, $c) {
  $f = 'func_get_args';
  var_dump($f());
}
function test_getargs_dyncall() {
  test_getargs_dyncall_impl(100, 'abc', false);
}

function test_getargs_cuf_impl($a, $b, $c) {
  $f = 'func_get_args';
  var_dump(call_user_func($f));
}
function test_getargs_cuf() {
  test_getargs_cuf_impl(100, 'abc', false);
}

function test_getargs_cuf_array_impl($a, $b, $c) {
  $f = 'func_get_args';
  var_dump(call_user_func_array($f, []));
}
function test_getargs_cuf_array() {
  test_getargs_cuf_array_impl(100, 'abc', false);
}

function test_getargs_map_impl($a, $b, $c) {
  $f = 'func_get_args';
  var_dump(array_map($f, ['a']));
}
function test_getargs_map() {
  test_getargs_map_impl(100, 'abc', false);
}

function test_getargs_errors() {
  $f = 'func_get_args';
  try { $f('abc', 100, false); } catch (Exception $e) { echo $e->getMessage().' in '.basename(__FILE__).' at line '.__LINE__."\n"; }
  try { array_map($f, [1]); } catch (Exception $e) { echo $e->getMessage().' in '.basename(__FILE__).' at line '.__LINE__."\n"; }
}

function get_current_test($all) {
  $tests = apc_fetch('tests');
  if (!is_array($tests)) {
    $tests = [];
    foreach ($all as $t) {
      $tests[] = [$t, 1];
      $tests[] = [$t, 2];
    }
  }
  if (empty($tests)) return null;
  $current = array_shift(&$tests);
  apc_store('tests', $tests);
  return $current;
}

function run_tests() {
  $all = [
    'test_getargs_dyncall',
    'test_getargs_cuf',
    'test_getargs_cuf_array',
    'test_getargs_errors',
  ];

  $test = get_current_test($all);
  if (is_null($test)) return;
  $func = $test[0];
  $iter = $test[1];
  echo "Running $func() #$iter....\n";
  $func();
  echo "$func() done\n";
}
