<?
	$connection = mysql_connect("db.ist.utl.pt","ist179112","base_dados2015");
	$db = mysql_select_db("ist179112",$connection);
	
	session_start();
	
	$user_check = $_SESSION['login_user'];
	
	$ses_sql = mysql_query("SELECT userid FROM utilizador where email='$user_check'", $connection);
	
	$row = mysql_fetch_assoc($ses_sql);
	$login_session = $row['userid'];
	if(!isset($login_session)){
		mysql_close($connection);
		header('Location: index.php');
	}
	
	try
    {
        $host = "db.ist.utl.pt";
        $user ="ist179112";
        $password = "base_dados2015";
        $dbname = $user;
    
        $db = new PDO("mysql:host=$host;dbname=$dbname", $user, $password);
        $db->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
    
        
    }
    catch (PDOException $e)
    {
        echo("<p>ERROR: {$e->getMessage()}</p>");
    }

?>