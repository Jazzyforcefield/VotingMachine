import java.awt.EventQueue;
import java.awt.BorderLayout;
import java.awt.EventQueue;

import javax.swing.JFrame;
import javax.swing.JOptionPane;
import javax.swing.JPanel;
import javax.swing.border.EmptyBorder;
import java.awt.Choice;
import java.awt.Button;
import javax.swing.JButton;
import javax.swing.JFileChooser;

import java.awt.event.ActionListener;
import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.awt.event.ActionEvent;
import java.awt.TextField;

import javax.swing.JFrame;
import javax.swing.JButton;
import javax.swing.JFileChooser;

import java.awt.event.ActionListener;
import java.io.File;
import java.awt.event.ActionEvent;
import java.awt.TextField;
import javax.swing.JTextField;
import javax.swing.JTextArea;
import java.awt.Color;
import javax.swing.JScrollBar;
import javax.swing.JScrollPane;

public class VotingCsvFile {
	JFrame frame = new JFrame("My JFrame Title");
	private final JButton btnNewButton = new JButton("Find CSV File");
	public static void main(String[] args) {
		EventQueue.invokeLater(new Runnable() {
			public void run() {
				try {
					VotingCsvFile window = new VotingCsvFile();
					window.frame.setVisible(true);
				} catch (Exception e) {
					e.printStackTrace();
				}
			}
		});
	}
	public VotingCsvFile() {
		initialize();
	}
	private void initialize() {
		frame = new JFrame();
		frame.getContentPane().setBackground(Color.ORANGE);
		frame.setBackground(Color.ORANGE);
		frame.setResizable(false);
		frame.setTitle("Welcome to Voting system");
		frame.setBounds(300, 0, 600, 500);
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		frame.getContentPane().setLayout(null);
		TextField path = new TextField();
		path.setBackground(Color.WHITE);
		path.setBounds(358, 44, 186, 35);
		// This Button named find CSV file, it will find the file
		// and show the whole path.
		btnNewButton.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				JFileChooser chooser = new JFileChooser();
				chooser.showOpenDialog(null);
				File f = chooser.getSelectedFile();
				String filename = f.getAbsolutePath();
				path.setText(filename);
			}
		});
		btnNewButton.setBounds(376, 85, 154, 92);
		frame.getContentPane().add(btnNewButton);
		frame.getContentPane().add(path);
		// a text area that print the text
		JScrollPane sp = new JScrollPane();
		sp.setSize(14, 263);
		sp.setLocation(200, 112);
		JTextArea show = new JTextArea();
		frame.getContentPane().add(show);
		
		frame.getContentPane().add(sp,BorderLayout.CENTER);
		show.setBounds(33, 44, 237, 404);
		
		JButton btnNewButton_1 = new JButton("Show Audit File");
		// This button is print the audit file text to the text area
		btnNewButton_1.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				BufferedReader audit = null;
				try {
					audit = new BufferedReader(new FileReader("audit.txt"));
					String line = "";
					String s = "";
					while ((line = audit.readLine())!= null) {
						s = s+line+"\n";	
					}
					show.setText(s);	
				}
				catch(IOException e2) {
					JOptionPane.showMessageDialog(null, "Could you just have your audit file first?");
				}	
			}
		});
		btnNewButton_1.setBounds(376, 225, 154, 92);
		frame.getContentPane().add(btnNewButton_1);
		JButton savefile = new JButton("save the audit file");
		savefile.setForeground(Color.BLACK);
		savefile.setBackground(Color.YELLOW);
		// This button is to save the text that is being displayed in the textarea.
		savefile.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				JFileChooser saveaudit = new JFileChooser() ;
				saveaudit.showSaveDialog(null);
				File f2 = saveaudit.getSelectedFile();
				try {
					
					FileWriter fw = new FileWriter(f2);
					String text = show.getText();
					fw.write(text);
					fw.close();
				}
				catch(IOException e2) {
					JOptionPane.showMessageDialog(null, "Boom");
				}		
			}
		});
		savefile.setBounds(376, 356, 154, 92);
		frame.getContentPane().add(savefile);
	}
}
