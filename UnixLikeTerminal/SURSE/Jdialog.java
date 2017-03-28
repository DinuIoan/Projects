import java.awt.FlowLayout;

import javax.swing.JDialog;
import javax.swing.JFrame;
import javax.swing.JTextArea;

public class Jdialog extends JFrame{
	JDialog d;
	JTextArea textarea = new JTextArea();
	public Jdialog(String nume,String mesaj)
	{
		
        d=new JDialog(this,nume,true);
        d.setSize(400, 400);
        d.setLayout(new FlowLayout());
        textarea.setText(mesaj);
        d.add(textarea);
        d.setVisible(true);
	}
}
