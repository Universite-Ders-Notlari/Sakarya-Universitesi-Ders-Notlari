package tr.edu.sakarya.nevzattasbasi.hafta5.otelbi;

import android.content.Context;
import android.view.View;
import android.view.ViewGroup;
import android.widget.BaseAdapter;
import android.widget.ImageView;
import android.widget.TextView;

import java.util.ArrayList;
import java.util.List;

/**
 * Created by NevzatTasbasi on 19.11.2018.
 */

public class OdaAdapter extends BaseAdapter {
    Context context;
    List<Oda> odalar;

    public OdaAdapter(Context context, ArrayList<Oda> odalar) {
        this.context = context;
        this.odalar = odalar;
    }

    @Override
    public int getCount() {
        return odalar.size();
    }

    @Override
    public Object getItem(int position) {
        return odalar.get(position);
    }

    @Override
    public long getItemId(int position) {
        return position;
    }

    @Override
    public View getView(int position, View convertView, ViewGroup parent) {
        if(convertView==null)
            convertView=View.inflate(context,R.layout.oda_layout,null);
        ImageView resim=(ImageView)convertView.findViewById(R.id.resim);
        TextView odaAd=(TextView)convertView.findViewById(R.id.txtAd);
        TextView odaFiyat=(TextView)convertView.findViewById(R.id.txtOdaTuru);

        Oda oda=odalar.get(position);

        resim.setImageResource(oda.getResimID());
        odaAd.setText(oda.getOdaAd());
        odaFiyat.setText(""+oda.getOdaFiyati());

        return convertView;
    }
}
