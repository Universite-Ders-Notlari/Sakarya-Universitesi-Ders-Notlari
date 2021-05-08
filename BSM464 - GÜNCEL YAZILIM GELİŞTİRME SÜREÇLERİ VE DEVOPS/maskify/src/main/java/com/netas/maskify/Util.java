package com.netas.maskify;

/**
 * Util
 */
public class Util {

  public static boolean isNumber(char currentCharacter) {
    try {
      Integer.parseInt(String.valueOf(currentCharacter));
      return true;
    } catch ( NumberFormatException e) {
      return false;
    }
  }
}