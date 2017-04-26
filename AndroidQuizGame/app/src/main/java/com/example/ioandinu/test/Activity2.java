/*
 * Copyright (C) 2012 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

package com.example.ioandinu.test;

import android.app.Activity;
import android.content.Intent;
import android.os.Bundle;
import android.os.Handler;
import android.view.View;
import android.widget.Button;
import android.widget.ProgressBar;
import android.widget.TextView;

import com.example.ioandinu.test.database.ItemsToGuess;
import com.example.ioandinu.test.database.Level2;

import io.realm.Realm;
import io.realm.RealmQuery;


/**
 * Example Activity to demonstrate the lifecycle callback methods.
 */
public class Activity2 extends Activity {
    private static final int PROGRESS = 0x1;

    private ProgressBar mProgress;
    private int mProgressStatus = 0;
    private ProgressBar mProgress2;
    private int mProgressStatus2 = 0;
    private long guessedLevel1 = 0;
    private long guessedLevel2 = 0;
    private Realm realm;
    private TextView textProgress;
    private TextView textProgress2;
    private TextView textBlock;
    private TextView textBlock2;
    private Button buttonLevel2;
    private Button buttonLevel3;

    private Handler mHandler = new Handler();


    @Override
    public void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_2);
        mProgress = (ProgressBar) findViewById(R.id.progress_bar);
        textProgress = (TextView) findViewById(R.id.text_progres);
        mProgress2 = (ProgressBar) findViewById(R.id.progress_bar2);
        textProgress2 = (TextView) findViewById(R.id.text_progres2);

        textBlock = (TextView) findViewById(R.id.text_block_level2);
        textBlock2 = (TextView) findViewById(R.id.text_block_level3);

        buttonLevel2 = (Button) findViewById(R.id.level_2);
        buttonLevel3 = (Button) findViewById(R.id.level_3);

        //realm = Realm.getInstance(Activity2.this);
        realm = Realm.getDefaultInstance();
        RealmQuery<ItemsToGuess> query = realm.where(ItemsToGuess.class);
        RealmQuery<Level2> query2 = realm.where(Level2.class);

        guessedLevel1 = query.equalTo("isGuessed",true).count();
        guessedLevel2 = query2.equalTo("isGuessed",true).count();

        textProgress.setText("" + (int) guessedLevel1 + "/" + 49);
        textProgress2.setText("" + (int) guessedLevel1 + "/" + 49);

        if(guessedLevel1 < 1){
            int remain = 40 - (int) guessedLevel1;
            textBlock.setEnabled(true);
            buttonLevel2.setVisibility(View.INVISIBLE);
            textBlock.setVisibility(View.VISIBLE);
            textBlock.setText("You need " + remain + " more stars to unlock level");
        }
        else{
            textBlock.setVisibility(View.INVISIBLE);
            buttonLevel2.setVisibility(View.VISIBLE);

        }
        if(guessedLevel1 < 80){
            int remain = 80 - (int) guessedLevel1;

            buttonLevel3.setVisibility(View.INVISIBLE);
            mProgress2.setVisibility(View.INVISIBLE);
            textProgress2.setVisibility(View.INVISIBLE);

            textBlock2.setVisibility(View.VISIBLE);
            textBlock2.setText("You need " + remain + " more stars to unlock level");
        }


        // Start lengthy operation in a background thread
        new Thread(new Runnable() {
            public void run() {
                while (mProgressStatus < 49) {

//                    RealmQuery<ItemsToGuess> query = realm.where(ItemsToGuess.class);
//                    guessedLevel1 = query.equalTo("isGuessed",true).count();
                    mProgressStatus = (int) guessedLevel1;

                    // Update the progress bar
                    mHandler.post(new Runnable() {
                        public void run() {
                            mProgress.setProgress(mProgressStatus);
                        }
                    });
                }
            }
        }).start();

        //TODO PROGRESS BAR LEVEL 2

        new Thread(new Runnable() {
            public void run() {
                while (mProgressStatus2 < 49) {

//                    RealmQuery<ItemsToGuess> query = realm.where(ItemsToGuess.class);
//                    guessedLevel1 = query.equalTo("isGuessed",true).count();
                    mProgressStatus2 = (int) guessedLevel2;

                    // Update the progress bar
                    mHandler.post(new Runnable() {
                        public void run() {
                            mProgress2.setProgress(mProgressStatus2);
                        }
                    });
                }
            }
        }).start();
    }

    @Override
    protected void onStart() {
        super.onStart();
    }

    @Override
    protected void onRestart() {
        super.onRestart();
    }

    @Override
    protected void onResume() {
        super.onResume();
    }

    @Override
    protected void onPause() {
        super.onPause();
    }

    @Override
    protected void onStop() {
        super.onStop();
    }

    @Override
    protected void onDestroy() {
        super.onDestroy();
    }

    public void back(View view){
        Intent i = new Intent(this, Activity1.class);
        startActivity(i);
    }

    public void level1(View view)
    {
        Intent i = new Intent(this, Activity3.class);
        i.putExtra("level","level1");
        startActivity(i);
    }

    public void level2(View view){
        Intent i = new Intent(this,Activity3.class);
        i.putExtra("level","level2");
        startActivity(i);
    }




}
