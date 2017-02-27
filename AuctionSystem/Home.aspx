<%@ Page Language="C#" AutoEventWireup="true" CodeFile="Home.aspx.cs" Inherits="AuctionSystem.Home" %>
<%@ Register TagPrefix="header" TagName="PageHeaderControl" Src="~/HeaderControl.ascx" %>
<!DOCTYPE html>
<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
	<meta charset="utf-8" />
	<title>Auction System</title>
	<style type="text/css">
	    .auto-style5 {
            width: 291px;
            margin-left: 520px;
        }
	</style>
</head>
<body>
	<div style="background-color: #FFCC66">
		<h2 style="text-align: center" >Auction System</h2>
	</div>
	<form id="form1" runat="server">
          <div class="auto-style5">
              <asp:Button ID="btnLogin" runat="server" Text="Login" Width="296px" OnClick="btnLogin_Click" Height="41px" />
              <br />
              <br />
              <br />
              <asp:Button ID="btnRegister" runat="server" Text="Registration" Width="296px" OnClick="btnRegister_Click" Height="41px" />
          </div>
	</form>
</body>
</html>
