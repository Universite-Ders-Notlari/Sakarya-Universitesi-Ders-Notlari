package com.netas.maskify;

/**
 * CreditCardMasker
 */
public class CreditCardMasker {

	public String mask(String input) {
    char[] chars = input.toCharArray();
    for(int i = 1; i < chars.length - 4; i++) {
      if(!Util.isNumber(chars[i]))
        continue;
      chars[i] = '#';
    }
		return String.valueOf(chars);
  }
  


  
}