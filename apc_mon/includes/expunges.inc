<?php
/**
 * Copyright: 2012 Joel Koglin
 * apcmon is distributed under the terms of the GPLv3
 * This file is part of apcmon
 */

/**
 * @return int The number of times the apc cache has been cleared
 */
function expunges() {
  $info = apc_cache_info();
  return $info['expunges'];
}