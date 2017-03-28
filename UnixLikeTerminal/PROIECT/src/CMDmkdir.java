
public class CMDmkdir extends WriteCommand{
	private String numeFolder;
	public boolean read;
	public boolean write;
	public String user ;
	

	public CMDmkdir(String nume,boolean read,boolean write,String user)
	{
	this.numeFolder = nume;	
	this.read = read;
	this.write = write;
	this.user = user;
	}
	
	public String toString()
	{
		return this.numeFolder;
	}


	@Override
	public void execute2(Folder folder) {
			Folder f1 = new Folder(numeFolder, read, write, user);
			folder.add(f1);
			Terminal.txtArea.append("<Succes\n");
		
	}

	@Override
	public void execute2(File file) {
		// TODO Auto-generated method stub
		
	}
	
	
}
