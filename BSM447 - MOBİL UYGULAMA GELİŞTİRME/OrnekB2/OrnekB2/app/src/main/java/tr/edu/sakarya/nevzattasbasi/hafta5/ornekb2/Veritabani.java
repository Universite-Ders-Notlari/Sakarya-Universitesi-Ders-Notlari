package tr.edu.sakarya.nevzattasbasi.hafta5.ornekb2;

import android.content.Context;
import android.database.sqlite.SQLiteDatabase;
import android.database.sqlite.SQLiteOpenHelper;

/**
 * Created by NevzatTasbasi on 3.12.2018.
 */

public class Veritabani extends SQLiteOpenHelper {
    public Veritabani(Context context) {
        super(context, "OtelB2", null, 1);
    }

    @Override
    public void onCreate(SQLiteDatabase db) {
        String sorgu="CREATE TABLe ODA(ID INTEGER PRIMARY KEY,AD TEXT NOT NULL,FIYAT INTEGER NOT NULL)";
        db.execSQL(sorgu);
    }

    @Override
    public void onUpgrade(SQLiteDatabase db, int oldVersion, int newVersion) {

    }
}
