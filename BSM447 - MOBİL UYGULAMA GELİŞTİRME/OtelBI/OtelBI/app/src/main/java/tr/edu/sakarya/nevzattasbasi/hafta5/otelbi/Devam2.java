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
import android.widget.AdapterView;
import android.widget.ListView;

import java.util.ArrayList;

public class Devam2 extends AppCompatActivity {
    ListView manzara;
    int mturu;
    ArrayList<Oda> manzaralar;
    OdaAdapter adt;
    SharedPreferences veriler;
    SharedPreferences.Editor yazici;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_devam2);

        veriler=getSharedPreferences("veriler",MODE_PRIVATE);
        yazici= veriler.edit();

        mturu=veriler.getInt("odaTuru",-1);
        manzara=(ListView)findViewById(R.id.manzara);

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


        manzaralar=new ArrayList<Oda>();
        manzaralar.add(new Oda(R.drawable.deniz,"Deniz Manzaralı",25));
        manzaralar.add(new Oda(R.drawable.dag,"Dağ manzaralı",18));
        manzaralar.add(new Oda(R.drawable.havuz,"Havuz Manzaralı",15));
        manzaralar.add(new Oda(R.drawable.koridor,"Koridor Manzaralı",5));

        adt=new OdaAdapter(getApplicationContext(),manzaralar);
        manzara.setAdapter(adt);



        manzara.setOnItemClickListener(new AdapterView.OnItemClickListener() {
            @Override
            public void onItemClick(AdapterView<?> parent, View view, int position, long id) {
                mturu=position;
            }
        });


    }
    public boolean onCreateOptionsMenu(Menu menu) {
        // Inflate the menu; this adds items to the action bar if it is present.
        getMenuInflater().inflate(R.menu.menu_sayfa2, menu);
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

    public void turkaydet(View view)
    {
        yazici.putInt("odaTuru",mturu);
        yazici.commit();
        Intent sayfa=new Intent(getApplicationContext(),SonSayfa.class);
        startActivity(sayfa);
    }
}
