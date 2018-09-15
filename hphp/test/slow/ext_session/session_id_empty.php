<?php

// Non-initialised session_id behaviour.
<<__EntryPoint>>
function main_session_id_empty() {
var_dump(session_id());

// session_id initialisation
var_dump(session_id("foo"));

// Initialised session_id behaviour.
var_dump(session_id());
}
