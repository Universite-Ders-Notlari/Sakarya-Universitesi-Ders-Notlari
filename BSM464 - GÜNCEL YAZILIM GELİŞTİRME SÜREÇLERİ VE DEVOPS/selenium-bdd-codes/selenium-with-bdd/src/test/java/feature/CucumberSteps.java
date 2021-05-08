package feature;

import cucumber.api.PendingException;
import cucumber.api.java.After;
import cucumber.api.java.Before;
import cucumber.api.java.en.And;
import cucumber.api.java.en.Given;

import io.github.bonigarcia.wdm.WebDriverManager;
import org.junit.Assert;
import org.openqa.selenium.By;
import org.openqa.selenium.WebDriver;
import org.openqa.selenium.chrome.ChromeDriver;

public class CucumberSteps {
    WebDriver driver;
    String baseUrl = "https://www.google.com.tr";

    @Before
    public void setupDriver() {
        WebDriverManager.chromedriver().forceDownload();
        WebDriverManager.chromedriver().setup();
    }

    @After
    public void tearDown() {
        if (driver != null)
            driver.quit();
    }

    @Given("^I open browser$")
    public void openBrowser() {
        driver = new ChromeDriver();
        driver.manage().window().maximize();
    }

    @Given("^I navigate to test site$")
    public void navigateSite() {

        driver.get(baseUrl);
    }


    @And("^I see Google Logo$")
    public void seeGoogleLogo() {

        Assert.assertEquals(1, driver.findElements(By.id("hplogo")).size());
    }

    @And("^I waif for ^[-+]?\\d+(\\.\\d+)?$\n seconds$")
    public void waitForSeconds(int milliSeconds) throws InterruptedException {
        Thread.sleep(milliSeconds);
    }

    @And("^I click \"([^\"]*)\" text$")
    public void iClickText(String text) throws Throwable {
        driver.findElement(By.id(text)).click();
    }
}
