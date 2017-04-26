package com.example.ioandinu.test.adapters;

import android.content.Context;
import android.view.View;
import android.view.ViewGroup;
import android.widget.BaseAdapter;
import android.widget.GridView;
import android.widget.ImageView;

import com.example.ioandinu.test.R;
import com.example.ioandinu.test.database.ItemsToGuess;

import io.realm.Realm;
import io.realm.RealmQuery;
import io.realm.RealmResults;


public class ImageAdapter extends BaseAdapter {
    private Context mContext;
    private Realm realm ;
    int i = 0;


    public ImageAdapter(Context c) {
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
            imageView.setLayoutParams(new GridView.LayoutParams(180, 180));
            imageView.setScaleType(ImageView.ScaleType.CENTER_CROP);
            imageView.setPadding(8, 8, 8, 8);
        } else {
            imageView = (ImageView) convertView;
        }
        i = 0;
        if(position < 49){
            RealmQuery<ItemsToGuess> query = realm.where(ItemsToGuess.class);
            RealmResults<ItemsToGuess> results = query.findAll();
            imageView.setImageResource(results.get(position).getDrawable());
        }
        return imageView;
    }

    private Integer[] mThumbIds =
            {
            R.drawable.a1, R.drawable.a2,
            R.drawable.a3, R.drawable.a4,
            R.drawable.a5, R.drawable.a6,
            R.drawable.a7, R.drawable.a8,
            R.drawable.a9, R.drawable.a10,
            R.drawable.a11, R.drawable.a12,
            R.drawable.a13, R.drawable.a14,
            R.drawable.a15, R.drawable.a16,
            R.drawable.a17, R.drawable.a18,
            R.drawable.a19, R.drawable.a20,
            R.drawable.a21, R.drawable.a22,
            R.drawable.a23, R.drawable.a24,
            R.drawable.a25, R.drawable.a26,
            R.drawable.a27, R.drawable.a28,
            R.drawable.a29, R.drawable.a30,
            R.drawable.a31, R.drawable.a32,
            R.drawable.a33, R.drawable.a34,
            R.drawable.a35, R.drawable.a36,
            R.drawable.a37, R.drawable.a38,
            R.drawable.a39, R.drawable.a40,
            R.drawable.a41, R.drawable.a42,
            R.drawable.a43, R.drawable.a44,
            R.drawable.a45, R.drawable.a46,
            R.drawable.a48, R.drawable.a49,
            R.drawable.a50,
    };
}
