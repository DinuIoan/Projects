package com.example.ioandinu.test;

import android.app.Activity;
import android.app.AlertDialog;
import android.content.Intent;
import android.os.Bundle;
import android.text.Editable;
import android.view.KeyEvent;
import android.view.View;
import android.view.inputmethod.EditorInfo;
import android.view.inputmethod.InputMethodManager;
import android.widget.CheckedTextView;
import android.widget.EditText;
import android.widget.ImageView;
import android.widget.TextView;

import com.example.ioandinu.test.database.ItemsToGuess;
import com.example.ioandinu.test.utils.Message;
import com.example.ioandinu.test.utils.SharedPreference;

import io.realm.Realm;
import io.realm.RealmQuery;

/**
 * Created by Ioan.Dinu on 7/28/2016.
 */




public class ActivityLevel1Picture1 extends Activity {

    private EditText editText;
    private CheckedTextView checkedTextView;
    boolean infinityIsChecked ;
    private SharedPreference sharedPreference;
    Activity context = this;
    boolean b ;
    Realm realm;
    int valueOfImage = 0;
    ImageView imageView;
    int idd = 0;
    private int guessed = 0;
    private String level;

    //Realm realm ;
    //ItemsToGuess textToGuess;

    @Override
    public void onCreate(final Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_1_picture1);
        Bundle extras = getIntent().getExtras();
        if (extras != null) {
            valueOfImage = extras.getInt("position");
            idd = extras.getInt("image");
            level = extras.getString("level");
        }

        editText = (EditText) findViewById(R.id.editText);
        checkedTextView = (CheckedTextView) findViewById(R.id.checkTextView);
        imageView = (ImageView) findViewById(R.id.image_picture);
        imageView.setImageResource(idd);
        Message.message(this,"" + idd);


       // realm = Realm.getInstance(this);
        realm = Realm.getDefaultInstance();



        View v = null;
        RealmQuery<ItemsToGuess> query = realm.where(ItemsToGuess.class);
        query.equalTo("id",valueOfImage);
        ItemsToGuess itemsToGuess = new ItemsToGuess();
        itemsToGuess = query.findFirst();
        String name = itemsToGuess.getTextToGuess();
        b = itemsToGuess.isGuessed();
        checkText(v,valueOfImage,name,b,itemsToGuess);


    }

    @Override
    protected void onStart() {
        super.onStart();
        if(infinityIsChecked == true){
            RealmQuery<ItemsToGuess> query = realm.where(ItemsToGuess.class);
            query.equalTo("id",valueOfImage);
            ItemsToGuess itemsToGuess = new ItemsToGuess();
            itemsToGuess = query.findFirst();
            b = itemsToGuess.isGuessed();
            editText.setFocusable(false);
            editText.setEnabled(false);
        }
    }

    @Override
    protected void onRestart() {
        super.onRestart();
        if(infinityIsChecked == true){
            RealmQuery<ItemsToGuess> query = realm.where(ItemsToGuess.class);
            query.equalTo("id",valueOfImage);
            ItemsToGuess itemsToGuess = new ItemsToGuess();
            itemsToGuess = query.findFirst();
            b = itemsToGuess.isGuessed();
            editText.setFocusable(false);
            editText.setEnabled(false);
        }
    }

    @Override
    protected void onResume() {
        super.onResume();
    }

    @Override
    protected void onPause() {
        super.onPause();
        if(infinityIsChecked == true){
            ItemsToGuess itemsToGuess = new ItemsToGuess();
            realm.beginTransaction();
            itemsToGuess.setGuessed(true);
            realm.commitTransaction();
        }
    }

    @Override
    protected void onStop() {
        super.onStop();
        if(infinityIsChecked == true){
            ItemsToGuess itemsToGuess = new ItemsToGuess();
            realm.beginTransaction();
            itemsToGuess.setGuessed(true);
            realm.commitTransaction();
        }

    }

    @Override
    protected void onDestroy() {
        super.onDestroy();
        if(infinityIsChecked == true){
            ItemsToGuess itemsToGuess = new ItemsToGuess();
            realm.beginTransaction();
            itemsToGuess.setGuessed(true);
            realm.commitTransaction();
        }
    }

    public void back(View view){
        Intent i = new Intent(this, Activity3.class);
        i.putExtra("level",level);
        startActivity(i);

    }



    public void checkText(View view, final int valueOfPicture, final String name, final boolean b, final ItemsToGuess itemsToGuess) {



        if(!b) {
            checkedTextView.setVisibility(View.INVISIBLE);
            editText.setOnEditorActionListener(new TextView.OnEditorActionListener() {
                @Override
                public boolean onEditorAction(TextView v, int actionId, KeyEvent event) {


                    if (actionId == EditorInfo.IME_ACTION_DONE) {


//                    if (!b) {
                        Editable inputText = editText.getText();
                        if (name.equals(inputText.toString())) {
                            infinityIsChecked = true;
                            realm.beginTransaction();
                            itemsToGuess.setGuessed(true);
                            guessed = 1;
                            itemsToGuess.setDrawable(R.drawable.a1checked);
                            realm.commitTransaction();



                            new AlertDialog.Builder(ActivityLevel1Picture1.this).setMessage("Good !").show();

                            // Closing keyboard
                            InputMethodManager imm = (InputMethodManager) getSystemService(ActivityLevel1Picture1.this.INPUT_METHOD_SERVICE);
                            imm.hideSoftInputFromWindow(editText.getWindowToken(), 0);
                            editText.setVisibility(View.INVISIBLE);
                            checkedTextView.setVisibility(View.VISIBLE);
                            checkedTextView.setText(name);

                        } else {

                            new AlertDialog.Builder(ActivityLevel1Picture1.this).setMessage("Wrong !").show();

                            // Closing keyboard
                            InputMethodManager imm = (InputMethodManager) getSystemService(ActivityLevel1Picture1.this.INPUT_METHOD_SERVICE);
                            imm.hideSoftInputFromWindow(editText.getWindowToken(), 0);
                        }
                        return true;

//                    else if(b){
//                        editText.setEnabled(false);
//                    }

                    }
                    return false;
                }
            });
        }else{
            editText.setEnabled(false);
            checkedTextView.setVisibility(View.VISIBLE);
            checkedTextView.setText(name);
        }


    }



}
