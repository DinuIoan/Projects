package com.example.ioandinu.test.utils;

import android.app.Notification;
import android.content.Context;
import android.database.SQLException;
import android.database.sqlite.SQLiteDatabase;
import android.database.sqlite.SQLiteOpenHelper;
import android.os.Message;

/**
 * Created by Ioan.Dinu on 8/2/2016.
 */
public class SQLiteClass extends SQLiteOpenHelper {
    public static final String DATABASE_NAME = "database";
    public static final String TABLE_NAME = "ITEMSTOGUESS";
    public static final String UID = "_id";
    public static final String NAME ="Name";
    private static final int DATABASE_VERSION = 1;
    private static final String CREATE_TABLE = "CREATE TABLE "+TABLE_NAME+" ("+UID+" INTEGER PRIMARY KEY AUTOINCREMENT, "+NAME+" VARCHAR(255));";
    private static final String DROP = "DROP TABLE "+TABLE_NAME+" IF EXISTS";

    private Context context;
    public SQLiteClass(Context context){
        super(context,DATABASE_NAME,null,DATABASE_VERSION);
        this.context = context;
        com.example.ioandinu.test.utils.Message.message(context,"constructor called");
    }
    @Override
    public void onCreate(SQLiteDatabase sqLiteDatabase) {
        try{
            sqLiteDatabase.execSQL(CREATE_TABLE);
            com.example.ioandinu.test.utils.Message.message(context,"onCreate() called");
        }catch(SQLException s){
            //s.printStackTrace();
            com.example.ioandinu.test.utils.Message.message(context,"onCreate() error called");
        }
    }

    @Override
    public void onUpgrade(SQLiteDatabase sqLiteDatabase, int i, int i1) {
        try {
            sqLiteDatabase.execSQL(DROP);
            onCreate(sqLiteDatabase);
            com.example.ioandinu.test.utils.Message.message(context,"onUpgrade() called");
        }catch(SQLException s){
            s.printStackTrace();
        }
    }
}
