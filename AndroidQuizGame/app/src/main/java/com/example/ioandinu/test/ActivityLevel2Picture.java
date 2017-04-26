package com.example.ioandinu.test;

import android.app.Activity;
import android.app.AlertDialog;
import android.content.Intent;
import android.support.v7.app.AppCompatActivity;
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
import com.example.ioandinu.test.database.Level2;
import com.example.ioandinu.test.utils.Message;
import com.example.ioandinu.test.utils.SharedPreference;

import io.realm.Realm;
import io.realm.RealmQuery;

public class ActivityLevel2Picture extends AppCompatActivity {
    private EditText editText2;
    private CheckedTextView checkedTextView2;
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

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_level2_picture);
        Bundle extras = getIntent().getExtras();
        if (extras != null) {
            valueOfImage = extras.getInt("position");
            idd = extras.getInt("image");
            level = extras.getString("level");
        }

        editText2 = (EditText) findViewById(R.id.editText2);
        checkedTextView2 = (CheckedTextView) findViewById(R.id.checkTextView2);
        imageView = (ImageView) findViewById(R.id.image_picture);
        imageView.setImageResource(idd);
        Message.message(this,"" + idd);


        // realm = Realm.getInstance(this);
        realm = Realm.getDefaultInstance();



        View v = null;
        RealmQuery<Level2> query = realm.where(Level2.class);
        query.equalTo("id",valueOfImage);
        Level2 level2 = new Level2();
        level2 = query.findFirst();
        String name = level2.getTextToGuess();
        b = level2.isGuessed();
        checkText(v,valueOfImage,name,b,level2);


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
            editText2.setFocusable(false);
            editText2.setEnabled(false);
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
            editText2.setFocusable(false);
            editText2.setEnabled(false);
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



    public void checkText(View view, final int valueOfPicture, final String name, final boolean b, final Level2 level2) {



        if(!b) {
            checkedTextView2.setVisibility(View.INVISIBLE);
            editText2.setOnEditorActionListener(new TextView.OnEditorActionListener() {
                @Override
                public boolean onEditorAction(TextView v, int actionId, KeyEvent event) {


                    if (actionId == EditorInfo.IME_ACTION_DONE) {


//                    if (!b) {
                        Editable inputText = editText2.getText();
                        if (name.equals(inputText.toString())) {
                            infinityIsChecked = true;
                            realm.beginTransaction();
                            level2.setGuessed(true);
                            guessed = 1;
                            level2.setDrawable(R.drawable.a1checked);
                            realm.commitTransaction();



                            new AlertDialog.Builder(ActivityLevel2Picture.this).setMessage("Good !").show();

                            // Closing keyboard
                            InputMethodManager imm = (InputMethodManager) getSystemService(ActivityLevel2Picture.this.INPUT_METHOD_SERVICE);
                            imm.hideSoftInputFromWindow(editText2.getWindowToken(), 0);
                            editText2.setVisibility(View.INVISIBLE);
                            checkedTextView2.setVisibility(View.VISIBLE);
                            checkedTextView2.setText(name);

                        } else {

                            new AlertDialog.Builder(ActivityLevel2Picture.this).setMessage("Wrong !").show();

                            // Closing keyboard
                            InputMethodManager imm = (InputMethodManager) getSystemService(ActivityLevel2Picture.this.INPUT_METHOD_SERVICE);
                            imm.hideSoftInputFromWindow(editText2.getWindowToken(), 0);
                        }
                        return true;

//                    else if(b){
//                        editText2.setEnabled(false);
//                    }

                    }
                    return false;
                }
            });
        }else{
            editText2.setEnabled(false);
            checkedTextView2.setVisibility(View.VISIBLE);
            checkedTextView2.setText(name);
        }



    }
}
