<?php
/**
 * Copyright: 2012 Joel Koglin
 * apcmon is distributed under the terms of the GPLv3
 * This file is part of apcmon
 */

/**
 * @return int The number of memory fragments
 */
function fragments() {
  $info = apc_sma_info();
  $fragments = 0;
  foreach ($info['block_lists'] as $segments) { //segments is an array of memory segments
    foreach ($segments as $segment) { //segment is an array of memory chunks in that segment
      $fragments += count($segment); //count how many chunks there are
      $fragments--; //don't count the first chunk of a segment as a fragment since there has to be one per segment
    }
  }
  return $fragments;
}