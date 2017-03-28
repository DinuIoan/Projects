
public class CMDecho extends SystemCommand{
	public String s;
	
	public CMDecho(String s){
		this.s = s;
	}
	
	@Override
	public void execute2(Folder folder) {
		Terminal.txtArea.append(s + "\n");
		
	}

	@Override
	public void execute2(File file) {
		// TODO Auto-generated method stub
		
	}

}
