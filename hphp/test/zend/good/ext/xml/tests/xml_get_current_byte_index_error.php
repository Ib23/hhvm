<?php
/* Prototype  : proto int xml_get_current_byte_index(resource parser)
 * Description: Get current byte index for an XML parser 
 * Source code: ext/xml/xml.c
 * Alias to functions: 
 */

echo "*** Testing xml_get_current_byte_index() : error conditions ***\n";

// Zero arguments
echo "\n-- Testing xml_get_current_byte_index() function with Zero arguments --\n";
try { var_dump( xml_get_current_byte_index() ); } catch (Exception $e) { echo "\n".'Warning: '.$e->getMessage().' in '.__FILE__.' on line '.__LINE__."\n"; }

//Test xml_get_current_byte_index with one more than the expected number of arguments
echo "\n-- Testing xml_get_current_byte_index() function with more than expected no. of arguments --\n";

$extra_arg = 10;
try { var_dump( xml_get_current_byte_index(null, $extra_arg) ); } catch (Exception $e) { echo "\n".'Warning: '.$e->getMessage().' in '.__FILE__.' on line '.__LINE__."\n"; }

echo "Done";
?>
