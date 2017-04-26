package com.example.ioandinu.test.adapters;

import android.content.Context;
import android.os.AsyncTask;
import android.view.View;
import android.view.ViewGroup;
import android.widget.BaseAdapter;
import android.widget.GridView;
import android.widget.ImageView;

import com.example.ioandinu.test.R;
import com.example.ioandinu.test.database.ItemsToGuess;
import com.example.ioandinu.test.database.Level2;

import io.realm.Realm;
import io.realm.RealmQuery;
import io.realm.RealmResults;

/**
 * Created by Ioan.Dinu on 8/17/2016.
 */
public class ImageAdapter2 extends BaseAdapter {
    private Context mContext;
    private Realm realm ;
    int i = 0;


    public ImageAdapter2(Context c) {
        mContext = c;
        int i = 0;

    }


    @Override
    public int getCount() {
        return mThumbIds.length;
    }

    @Override
    public Integer getItem(int i) {
        return mThumbIds[i];
    }

    @Override
    public long getItemId(int i) {
        return mThumbIds[i];
    }

    // create a new ImageView for each item referenced by the Adapter
    public View getView(int position, View convertView, ViewGroup parent) {
        ImageView imageView;
        //realm = Realm.getInstance(mContext);
        realm = Realm.getDefaultInstance();
        if (convertView == null) {
            // if it's not recycled, initialize some attributes
            imageView = new ImageView(mContext);
            imageView.setLayoutParams(new GridView.LayoutParams(380,380));
            imageView.setScaleType(ImageView.ScaleType.FIT_CENTER);
            imageView.setPadding(2, 2, 2, 2);
        } else {
            imageView = (ImageView) convertView;
        }
        i = 0;
        if(position < 49){
            RealmQuery<Level2> query = realm.where(Level2.class);
            RealmResults<Level2> results = query.findAll();
            imageView.setImageResource(results.get(position).getDrawable());
        }
        return imageView;
    }

    private Integer[] mThumbIds =
            {
                    R.drawable.b1, R.drawable.b2,
                    R.drawable.b3, R.drawable.b4,
                    R.drawable.b5, R.drawable.b6,
                    R.drawable.b7, R.drawable.b8,
                    R.drawable.b9, R.drawable.b10,
                    R.drawable.b11, R.drawable.b12,
                    R.drawable.b13, R.drawable.b14,
                    R.drawable.b15, R.drawable.b16,
                    R.drawable.b17, R.drawable.b18,
                    R.drawable.b19, R.drawable.b20,
                    R.drawable.b21, R.drawable.b22,
                    R.drawable.b23, R.drawable.b24,
                    R.drawable.b25, R.drawable.b26,
                    R.drawable.b27, R.drawable.b28,
                    R.drawable.b29, R.drawable.b30,
                    R.drawable.b31, R.drawable.b32,
                    R.drawable.b33, R.drawable.b34,
                    R.drawable.b35, R.drawable.b36,
                    R.drawable.b37, R.drawable.b38,
                    R.drawable.b39, R.drawable.b40,
                    R.drawable.b41, R.drawable.b42,
                    R.drawable.b43, R.drawable.b44,
                    R.drawable.b45, R.drawable.b46,
                    R.drawable.b48, R.drawable.b49,
            };
}
