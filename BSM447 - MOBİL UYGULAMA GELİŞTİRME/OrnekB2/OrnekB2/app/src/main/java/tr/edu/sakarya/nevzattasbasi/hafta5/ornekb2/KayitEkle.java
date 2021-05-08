package tr.edu.sakarya.nevzattasbasi.hafta5.ornekb2;

import android.database.sqlite.SQLiteDatabase;
import android.os.Bundle;
import android.support.design.widget.FloatingActionButton;
import android.support.design.widget.Snackbar;
import android.support.v7.app.AppCompatActivity;
import android.support.v7.widget.Toolbar;
import android.view.View;
import android.widget.EditText;
import android.widget.Toast;

public class KayitEkle extends AppCompatActivity {
    EditText edtID,edtAD,edtFiyat;
    Veritabani vt;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_kayit_ekle);

        vt=new Veritabani(this);

        edtID=(EditText)findViewById(R.id.edtID);
        edtAD=(EditText)findViewById(R.id.edtAD);
        edtFiyat=(EditText)findViewById(R.id.edtFiyat);

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

    public void ekle(View view)
    {
        SQLiteDatabase db=vt.getWritableDatabase();
        int id=Integer.parseInt(edtID.getText().toString());
        String ad=edtAD.getText().toString();
        String fiyat=edtFiyat.getText().toString();

        String sorgu="INSERT INTO ODA VALUES ("+id+",'"+ad+"',"+fiyat+")";
        db.execSQL(sorgu);

        Toast.makeText(getApplicationContext(),"Kayıt Eklendi",Toast.LENGTH_LONG).show();


        db.close();
    }
}
