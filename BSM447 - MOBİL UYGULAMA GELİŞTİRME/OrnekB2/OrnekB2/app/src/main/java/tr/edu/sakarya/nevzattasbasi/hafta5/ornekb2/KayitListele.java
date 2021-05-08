package tr.edu.sakarya.nevzattasbasi.hafta5.ornekb2;

import android.database.Cursor;
import android.database.sqlite.SQLiteDatabase;
import android.os.Bundle;
import android.support.design.widget.FloatingActionButton;
import android.support.design.widget.Snackbar;
import android.support.v7.app.AppCompatActivity;
import android.support.v7.widget.Toolbar;
import android.view.View;
import android.widget.ArrayAdapter;
import android.widget.ListView;
import android.widget.Toast;

public class KayitListele extends AppCompatActivity {
    ListView liste;
    Veritabani vt;
    String[] odalar;
    ArrayAdapter<String> adapter;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_kayit_listele);

        liste=(ListView)findViewById(R.id.liste);
        vt=new Veritabani(this);
        SQLiteDatabase db=vt.getReadableDatabase();

        String sorgu="SELECT * FROM ODA";
        Cursor okunan=db.rawQuery(sorgu,null);

        if(okunan.getCount()<=0)
            Toast.makeText(getApplicationContext(),"Kayıt Bulunamadı",Toast.LENGTH_LONG).show();
        else
        {
            odalar=new String[okunan.getCount()];
            int i=0;
            while (okunan.moveToNext())
            {
                int id=okunan.getInt(okunan.getColumnIndex("ID"));
                String ad=okunan.getString(okunan.getColumnIndex("AD"));
                int fiyat=okunan.getInt(okunan.getColumnIndex("FIYAT"));
                String satir="ID : "+id+" AD:"+ad+" Fiyat : "+fiyat;
                odalar[i++]=satir;
            }
            adapter=new ArrayAdapter<String>(getApplicationContext(),android.R.layout.simple_list_item_1,odalar);
            liste.setAdapter(adapter);
        }


        db.close();

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

}
