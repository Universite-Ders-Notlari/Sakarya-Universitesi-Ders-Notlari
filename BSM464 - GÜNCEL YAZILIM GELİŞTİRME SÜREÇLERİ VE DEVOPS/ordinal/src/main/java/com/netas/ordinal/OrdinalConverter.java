package com.netas.ordinal;

/**
 * OrdinalConverter
 */
public class OrdinalConverter {

	public String convert(int input) {
  
    int lastDigit = input % 10;
    int lastTwoDigit = input % 100;

    boolean isExceptional = lastTwoDigit >= 11 && lastTwoDigit <= 13;

    String suffix = "th";

    if(!isExceptional){
      if(lastDigit == 2) {
        suffix = "nd";
      } else if(lastDigit == 3){
        suffix = "rd";
      }else if(lastDigit == 1) {
        suffix = "st";
      }
    }
    return input + suffix;
	}

  
}