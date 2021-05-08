package tr.edu.sakarya.nevzattasbasi.hafta5.otelbi;

import android.content.Intent;
import android.content.SharedPreferences;
import android.os.Bundle;
import android.support.design.widget.FloatingActionButton;
import android.support.design.widget.Snackbar;
import android.support.v7.app.AppCompatActivity;
import android.support.v7.widget.Toolbar;
import android.view.ContextMenu;
import android.view.Menu;
import android.view.MenuInflater;
import android.view.MenuItem;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.RadioButton;
import android.widget.Toast;

public class Anasayfa extends AppCompatActivity {
    EditText ks;
    RadioButton toda,ioda,soda;
    Button btnIleri1;
    int kisiSayisi;
    int odaTipi;
    SharedPreferences veriler;
    SharedPreferences.Editor yazici;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_anasayfa);

        veriler=getSharedPreferences("veriler",MODE_PRIVATE);
        yazici=veriler.edit();

        kisiSayisi=veriler.getInt("ks",-1);
        odaTipi=veriler.getInt("odaTipi",-1);

        ks=(EditText)findViewById(R.id.ks);

        ks.setText(""+kisiSayisi);

        toda=(RadioButton)findViewById(R.id.toda);
        ioda=(RadioButton)findViewById(R.id.ioda);
        soda=(RadioButton)findViewById(R.id.soda);

        if(odaTipi==0)
            toda.setChecked(true);
        else if(odaTipi==1)
            ioda.setChecked(true);
        else if(odaTipi==2)
            soda.setChecked(true);



        btnIleri1=(Button)findViewById(R.id.btnIleri1);

        registerForContextMenu(ks);

        Toolbar toolbar = (Toolbar) findViewById(R.id.toolbar);
        setSupportActionBar(toolbar);

        FloatingActionButton fab = (FloatingActionButton) findViewById(R.id.fab);
        fab.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                Snackbar.make(view, "Hatalı Veri Girişi", Snackbar.LENGTH_LONG)
                        .setAction("Action", null).show();
            }
        });

        View.OnClickListener deneme=new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                int hata=0;
                if(ks.getText().toString().length()<=0)
                {
                    Toast.makeText(getApplicationContext(),"Lütfen Kişi Sayısını Giriniz.",Toast.LENGTH_LONG).show();
                    hata=1;
                }
                else {
                    kisiSayisi = Integer.parseInt(ks.getText().toString());
                    if (kisiSayisi < 1 || kisiSayisi > 4) {
                        Toast.makeText(getApplicationContext(), "Kişi Sayısı Yanlış Girildi", Toast.LENGTH_LONG).show();
                        hata = 1;
                    }
                }

                if(toda.isChecked()) odaTipi=0;
                if(ioda.isChecked()) odaTipi=1;
                if(soda.isChecked()) odaTipi=2;

                if(odaTipi==-1) {
                    Toast.makeText(getApplicationContext(), "LütfenOda Türü Seçiniz.", Toast.LENGTH_LONG).show();
                    hata = 1;
                }

                if(hata==0)
                {
                    yazici.putInt("ks",kisiSayisi);
                    yazici.putInt("odaTipi",odaTipi);
                    yazici.commit();
                    Intent sayfa2=new Intent(getApplicationContext(),Devam2.class);
                    startActivity(sayfa2);

                }
            }
        };

        btnIleri1.setOnClickListener(deneme);

    }

    @Override
    public boolean onCreateOptionsMenu(Menu menu) {
        // Inflate the menu; this adds items to the action bar if it is present.
        getMenuInflater().inflate(R.menu.menu_anasayfa, menu);
        return true;
    }

    @Override
    public boolean onOptionsItemSelected(MenuItem item) {
        // Handle action bar item clicks here. The action bar will
        // automatically handle clicks on the Home/Up button, so long
        // as you specify a parent activity in AndroidManifest.xml.
        int id = item.getItemId();

        //noinspection SimplifiableIfStatement
        if (id == R.id.syf2) {
            Intent sayfa2=new Intent(getApplicationContext(),Devam2.class);
            startActivity(sayfa2);
            return true;
        }
        if (id == R.id.sonsyf) {
            Intent sayfa2=new Intent(getApplicationContext(), SonSayfa.class);
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
    public void onCreateContextMenu(ContextMenu menu, View v, ContextMenu.ContextMenuInfo menuInfo)
    {
        super.onCreateContextMenu(menu, v, menuInfo);
        MenuInflater inf = getMenuInflater();
        inf.inflate(R.menu.menu_acilan, menu);
    }
    public boolean onContextItemSelected(MenuItem item) {
        if(item.getItemId()==R.id.secim2)
            ks.setText("2");
        if(item.getItemId()==R.id.secim3)
            ks.setText("3");
        if(item.getItemId()==R.id.secim4)
            ks.setText("4");
        return true;
    }
}
