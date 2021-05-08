package com.netas.maskify;

import static org.assertj.core.api.Assertions.*;

import org.junit.Before;
import org.junit.Test;

/**
 * CreditCardMaskerTest
 */
public class CreditCardMaskerTest {

  CreditCardMasker masker;

  @Before
  public void init(){
    masker = new CreditCardMasker();
  }

  @Test
  public void mask_whenCreditCardNumberIsShort_returnsUnmasked(){
    
    String input = "54321";
    String output = masker.mask(input);
    assertThat(output).isEqualTo("54321");
  }

  @Test
  public void mask_whenCreditCardNumberIsBasic_returnsMaskedOtherThanFirstAndLastFourDigit(){
    String input = "5512103073210694";
    String output = masker.mask(input);
    assertThat(output).isEqualTo("5###########0694");
  }

  @Test
  public void mask_whenCreditCardNumberIsDashed_returnsMaskedOtherThanFirstAndLastFourDigit(){
    String input = "4556-3646-0793-5616";
    String output = masker.mask(input);
    assertThat(output).isEqualTo("4###-####-####-5616");
  }

  @Test
  public void mask_whenCreditCardNumberIs11Digits_returnsMaskedOtherThanFirstAndLastFourDigit(){
    String input = "64607935616";
    String output = masker.mask(input);
    assertThat(output).isEqualTo("6######5616");
  }
  
  @Test
  public void mask_whenCreditCardNumberIsAllLetter_returnsUnmasked(){
    String input = "ABCD-EFGH-IJKLM-NOPQ";
    String output = masker.mask(input);
    assertThat(output).isEqualTo("ABCD-EFGH-IJKLM-NOPQ");
  }

  @Test
  public void mask_whenCreditCardNumberMixed_returnsMaskedOtherThanFirstAndLastFourDigit(){
    String input = "A1234567BCDEFG89HI";
    String output = masker.mask(input);
    assertThat(output).isEqualTo("A#######BCDEFG89HI");
  }

}