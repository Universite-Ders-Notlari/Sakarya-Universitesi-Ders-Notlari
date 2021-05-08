package tr.edu.sakarya.nevzattasbasi.hafta5.ornekb2;

import android.app.ProgressDialog;
import android.content.Intent;
import android.os.Bundle;
import android.support.design.widget.FloatingActionButton;
import android.support.design.widget.Snackbar;
import android.support.v7.app.AppCompatActivity;
import android.support.v7.widget.Toolbar;
import android.view.Menu;
import android.view.MenuItem;
import android.view.View;
import android.widget.ArrayAdapter;
import android.widget.ListView;
import android.widget.Toast;

import com.android.volley.RequestQueue;
import com.android.volley.Response;
import com.android.volley.VolleyError;
import com.android.volley.toolbox.StringRequest;
import com.android.volley.toolbox.Volley;

import org.json.JSONArray;
import org.json.JSONException;
import org.json.JSONObject;

import java.util.ArrayList;

public class MainActivity extends AppCompatActivity {
    ListView liste;
    ProgressDialog dialog;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        liste=(ListView)findViewById(R.id.meyveliste);

        dialog = new ProgressDialog(this);
        dialog.setMessage("Loading....");
        dialog.show();

        String url="https://www.thecrazyprogrammer.com/example_data/fruits_array.json";
        StringRequest request = new StringRequest(url,new Response.Listener<String>() {
                    @Override
                    public void onResponse(String string) {
                        JsonDataparcala(string);
                    }
        }, new Response.ErrorListener() {
            @Override
            public void onErrorResponse(VolleyError volleyError) {
                Toast.makeText(getApplicationContext(), "Hata Var!!", Toast.LENGTH_SHORT).show();
                        dialog.dismiss();
            }
        });

        RequestQueue rQueue = Volley.newRequestQueue(MainActivity.this);
        rQueue.add(request);

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

    @Override
    public boolean onCreateOptionsMenu(Menu menu) {
        // Inflate the menu; this adds items to the action bar if it is present.
        getMenuInflater().inflate(R.menu.menu_main, menu);
        return true;
    }

    @Override
    public boolean onOptionsItemSelected(MenuItem item) {
        // Handle action bar item clicks here. The action bar will
        // automatically handle clicks on the Home/Up button, so long
        // as you specify a parent activity in AndroidManifest.xml.
        int id = item.getItemId();

        //noinspection SimplifiableIfStatement
        if (id == R.id.kytEkle) {
            Intent sayfa=new Intent(getApplicationContext(),KayitEkle.class);
            startActivity(sayfa);
            return true;
        }
        if (id == R.id.kytListele) {
            Intent sayfa=new Intent(getApplicationContext(),KayitListele.class);
            startActivity(sayfa);
            return true;
        }
        if (id == R.id.cikis) {
            finish();
            return true;
        }
        return super.onOptionsItemSelected(item);
    }
    public void JsonDataparcala(String jsonString) {
        try {
            JSONObject object = new JSONObject(jsonString);
            JSONArray fruitsArray = object.getJSONArray("fruits");
            ArrayList al = new ArrayList();
            for(int i = 0; i < fruitsArray.length(); ++i) {
                al.add(fruitsArray.getString(i));
            }
            ArrayAdapter adapter = new ArrayAdapter(this, android.R.layout.simple_list_item_1, al);
            liste.setAdapter(adapter);
        }
        catch (JSONException e) {
            e.printStackTrace();
        }
        dialog.dismiss();
    }

}
