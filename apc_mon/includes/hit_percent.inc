<?php
/**
 * Copyright: 2012 Joel Koglin
 * apcmon is distributed under the terms of the GPLv3
 * This file is part of apcmon
 */

/**
 * @return float
 */
function hit_percent() {
  $info = apc_cache_info();
  $total_hits = $info['num_hits'] + $info['num_misses'];
  return floor((($info['num_hits']) / ($total_hits)) * 100);
}