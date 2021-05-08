package tr.edu.sakarya.nevzattasbasi.hafta5.otelbi;

import android.content.Intent;
import android.content.SharedPreferences;
import android.os.Bundle;
import android.support.design.widget.FloatingActionButton;
import android.support.design.widget.Snackbar;
import android.support.v7.app.AppCompatActivity;
import android.support.v7.widget.Toolbar;
import android.view.Menu;
import android.view.MenuItem;
import android.view.View;
import android.widget.TextView;

public class SonSayfa extends AppCompatActivity {
    TextView txtKisiSayisi,txtOdaTipi,txtOdaTuru,txtFiyat;
    SharedPreferences veriler;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_son_sayfa);

        veriler=getSharedPreferences("veriler",MODE_PRIVATE);

        txtKisiSayisi=(TextView)findViewById(R.id.txtKisiSayisi);
        txtOdaTipi=(TextView)findViewById(R.id.txtOdaTipi);
        txtOdaTuru=(TextView)findViewById(R.id.txtOdaTuru);
        txtFiyat=(TextView)findViewById(R.id.txtFiyat);


        int ks=veriler.getInt("ks",-1);
        if(ks==-1)
            txtKisiSayisi.setText("Kişi Sayısı : Kişi Sayısı Girilmedi");
        else
            txtKisiSayisi.setText("Kişi Sayısı : "+ks);

        int odaTipi=veriler.getInt("odaTipi",-1);
        if(odaTipi==-1)
            txtOdaTipi.setText("Oda Tipi : Oda Tipi Seçilmedi");
        else if(odaTipi==0)
            txtOdaTipi.setText("Oda Tipi : Tek Odalı");
        else if(odaTipi==1)
            txtOdaTipi.setText("Oda Tipi : İki Odalı");
        else if(odaTipi==2)
            txtOdaTipi.setText("Oda Tipi : Suit Oda");

        int odaTuru=veriler.getInt("odaTuru",-1);

        if(odaTuru==-1)
            txtOdaTuru.setText("Oda Turu : Seçilmedi");
        else if(odaTuru==0)
            txtOdaTuru.setText("Oda Turu : Deniz Manzaralı");
        else if(odaTuru==1)
            txtOdaTuru.setText("Oda Turu : Dağ Manzaralı");
        else if(odaTuru==2)
            txtOdaTuru.setText("Oda Turu : Havuz Manzaralı");
        else if(odaTuru==3)
            txtOdaTuru.setText("Oda Turu : Koridor Manzaralı");


        Toolbar toolbar = (Toolbar) findViewById(R.id.toolbar);
        setSupportActionBar(toolbar);

        FloatingActionButton fab = (FloatingActionButton) findViewById(R.id.fab);
        fab.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                Snackbar.make(view, "Replace with your own action", Snackbar.LENGTH_LONG)
                        .setAction("Action", null).show();
            }
        });
    }
    public boolean onCreateOptionsMenu(Menu menu) {
        // Inflate the menu; this adds items to the action bar if it is present.
        getMenuInflater().inflate(R.menu.menu_sonsayfa, menu);
        return true;
    }

    @Override
    public boolean onOptionsItemSelected(MenuItem item) {
        // Handle action bar item clicks here. The action bar will
        // automatically handle clicks on the Home/Up button, so long
        // as you specify a parent activity in AndroidManifest.xml.
        int id = item.getItemId();

        //noinspection SimplifiableIfStatement
        if (id == R.id.giris) {
            Intent sayfa2=new Intent(getApplicationContext(),Anasayfa.class);
            startActivity(sayfa2);
            return true;
        }
        if (id == R.id.syf2) {
            Intent sayfa2=new Intent(getApplicationContext(),Devam2.class);
            startActivity(sayfa2);
            return true;
        }
        if(item.getItemId()==R.id.cikis)
        {
            finish();
            //System.exit(0);
        }

        return super.onOptionsItemSelected(item);
    }
}
