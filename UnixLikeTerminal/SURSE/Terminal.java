import java.awt.BorderLayout;
import java.awt.Color;
import java.awt.Dimension;
import java.awt.Font;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.KeyEvent;
import java.awt.event.KeyListener;
import java.util.Scanner;

import javax.swing.DefaultListModel;
import javax.swing.JFrame;
import javax.swing.JList;
import javax.swing.JPanel;
import javax.swing.JScrollPane;
import javax.swing.JTextArea;
import javax.swing.JTextField;
import javax.swing.SwingUtilities;

public class Terminal extends JFrame implements KeyListener{
	JFrame frm = new JFrame();
	JTextField txtField = new JTextField();
	JPanel panel = new JPanel();
    static JTextArea txtArea = new JTextArea();
    static JScrollPane scrollPane = new JScrollPane(txtArea);
    Font font = new Font("Serif",Font.BOLD,12);
   

    public Terminal(String text){

    	getContentPane().add(panel);
		panel.setLayout(null);
		setSize(700,700);
		setTitle(text);
		setDefaultCloseOperation(EXIT_ON_CLOSE);
		setLocation(200,20);
		setResizable(false);
		txtField.setBounds(0, 640, 700, 30);
		txtField.setForeground(Color.white);
		txtField.setFont(font);
		txtArea.setForeground(Color.white);
		txtArea.setEditable(false);
		txtField.setBackground(Color.black);
		txtArea.setBackground(Color.black);
		scrollPane.setBounds(0,0,700,640);
		panel.setBackground(Color.black);
		panel.add(scrollPane);
		panel.add(txtField);
		panel.setVisible(true);
    }
    
    private void showPrompt() {
    	
        txtField.setText(txtField.getText() );
        txtField.addKeyListener(this);
    }
    
    public void open() {
        SwingUtilities.invokeLater(new Runnable() {
            public void run() {           	
                showPrompt();             
            }
        });
    }
    
    public void keyTyped(KeyEvent e) {}
	public void keyReleased(KeyEvent e) {}
	public void keyPressed(KeyEvent e) {
		
		if (e.getSource() == txtField) {
			if (e.getKeyCode() == KeyEvent.VK_ENTER) {
				String s = txtField.getText();
				txtArea.append(">" + txtField.getText()+ "\n");
				Factory f = new Factory();
				Command cmd = f.getCommand(s);
				cmd.execute(CurrentFolder.Home);
				if(s.contains("userinfo"))
				{
					if(s.contains("-POO"))
					{
						
						DefaultListModel model = new DefaultListModel();
						model.addElement("Username: " + Logger.getUser().username);
						model.addElement("Nume: " + Logger.getUser().nume);
						model.addElement("Prenume: " + Logger.getUser().prenume);
						model.addElement("DataCreare " + Logger.getUser().dataCreare);
						model.addElement("DataLogare: " + Logger.getUser().dataLogare);
						JList list = new JList(model);
						list.setLayoutOrientation(JList.HORIZONTAL_WRAP);
						list.setVisibleRowCount(-1);
						list.setVisible(true);
						frm.add(list);
						frm.pack();
						frm.setVisible(true);
						
						
					}
				}
				txtField.setText("");
				
				
			}
		}
	}
    
    private static final class TerminalHolder {
        static final Terminal INSTANCE = new Terminal("Terminal");
    }
    
    public static Terminal getInstance() {
        return TerminalHolder.INSTANCE;
    }

	
}