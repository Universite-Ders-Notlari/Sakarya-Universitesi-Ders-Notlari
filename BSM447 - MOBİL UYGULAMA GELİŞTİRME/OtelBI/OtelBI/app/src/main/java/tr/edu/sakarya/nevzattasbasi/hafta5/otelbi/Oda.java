package tr.edu.sakarya.nevzattasbasi.hafta5.otelbi;

/**
 * Created by NevzatTasbasi on 19.11.2018.
 */

public class Oda {
    private int resimID;
    private String odaAd;
    private int odaFiyati;

    public Oda(int resimID, String odaAd, int odaFiyati) {
        this.resimID = resimID;
        this.odaAd = odaAd;
        this.odaFiyati = odaFiyati;
    }

    public void setResimID(int resimID) {
        this.resimID = resimID;
    }

    public void setOdaAd(String odaAd) {
        this.odaAd = odaAd;
    }

    public void setOdaFiyati(int odaFiyati) {
        this.odaFiyati = odaFiyati;
    }

    public int getResimID() {
        return resimID;
    }

    public String getOdaAd() {
        return odaAd;
    }

    public int getOdaFiyati() {
        return odaFiyati;
    }
}
