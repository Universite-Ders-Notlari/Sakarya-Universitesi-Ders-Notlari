package com.sakarya.selenium;

import io.github.bonigarcia.wdm.WebDriverManager;
import org.openqa.selenium.WebDriver;
import org.openqa.selenium.chrome.ChromeDriver;
import org.testng.annotations.*;

public class Example {
    WebDriver driver;
    String baseUrl;

    @BeforeSuite
    public void setUpClass() {
        WebDriverManager.chromedriver().setup();
    }

    @BeforeTest
    public void setupTest() {
        driver = new ChromeDriver();
        baseUrl = "https://www.google.com.tr/";
    }

    @AfterTest
    public void tearDown() {
        if (driver != null)
            driver.quit();
    }

    @Test
    public void exampleTest() throws InterruptedException {
        driver.get(baseUrl);
        Thread.sleep(5000);
    }
}
