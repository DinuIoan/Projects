
public class CMDuserinfo extends SystemCommand{
	
	public CMDuserinfo()
	{
	}


	@Override
	public void execute2(Folder folder) {
		Terminal.txtArea.append("Username: " + Logger.getUser().username + "\n" +"Nume: " + Logger.getUser().nume + "\n" +"Prenume: " + Logger.getUser().prenume + "\n" +"DataCreare " + Logger.getUser().dataCreare + "\n" +"DataLogare: " + Logger.getUser().dataLogare + "\n");
		
	}


	@Override
	public void execute2(File file) {
		// TODO Auto-generated method stub
		
	}
	
	
}
