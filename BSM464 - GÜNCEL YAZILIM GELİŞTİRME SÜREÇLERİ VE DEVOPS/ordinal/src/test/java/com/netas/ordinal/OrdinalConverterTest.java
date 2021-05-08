package com.netas.ordinal;

import static org.assertj.core.api.Assertions.*;

import org.junit.Before;
import org.junit.Test;

/**
 * OrdinalConverterTest
 */
public class OrdinalConverterTest {

  OrdinalConverter converter;

  @Before
  public void init(){
    converter = new OrdinalConverter();
  }
  

  @Test
  public void convert_whenNumberEndsWith1_returnsSuffixST(){
    int input = 1;
    String output = converter.convert(input);
    assertThat(output).isEqualTo("1st");
  }

  @Test
  public void convert_whenNumberEndsWith2_returnsSuffixND(){
    int input = 2;
    String output = converter.convert(input);
    assertThat(output).isEqualTo("2nd");
  }

  @Test
  public void convert_whenNumberEndsWith3_returnsSuffixRD(){
    int input = 3;
    String output = converter.convert(input);
    assertThat(output).isEqualTo("3rd");
  }

  @Test
  public void convert_whenNumberEndsWithOther_returnsSuffixTH(){
    int input = 4;
    String output = converter.convert(input);
    assertThat(output).isEqualTo("4th");
  }
  @Test
  public void convert_whenNumberEndsWith11_returnsSuffixTH(){
    int input = 11;
    String output = converter.convert(input);
    assertThat(output).isEqualTo("11th");
  } 

  @Test
  public void convert_whenNumberEndsWith12_returnsSuffixTH(){
    int input = 12;
    String output = converter.convert(input);
    assertThat(output).isEqualTo("12th");
  } 

  @Test
  public void convert_whenNumberEndsWith13_returnsSuffixTH(){
    int input = 13;
    String output = converter.convert(input);
    assertThat(output).isEqualTo("13th");
  } 

  @Test
  public void convert_whenNumberIs22_returnsSuffixND(){
    int input = 22;
    String output = converter.convert(input);
    assertThat(output).isEqualTo("22nd");
  } 
}