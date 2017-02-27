<%@ Page Language="C#" AutoEventWireup="true" CodeFile="Login.aspx.cs" Inherits="AuctionSystem.Login" %>
<%@ Register TagPrefix="header" TagName="HeaderControl" Src="~/HeaderControl.ascx" %>
<%@ Register TagPrefix="user" TagName="LoginControl" Src="~/LoginControl.ascx" %>
<!DOCTYPE html>
<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <title>Seller Login</title>
    <style type="text/css">
        .auto-style3 {
            margin-left: 160px;
        }
    </style>
</head>
<body>
    <header:HeaderControl runat="server" />
    <h3>Login&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; </h3>
    <hr />
    <form runat="server" visible="True">
        <user:LoginControl ID="loginControl" BackColor="#ccccff" runat="server" />
        &nbsp;&nbsp; &nbsp;<asp:Label ID="LabelLoginError" runat="server" ForeColor="Red" Text="LabelLoginError" Visible="False"></asp:Label>
        &nbsp;&nbsp;&nbsp;<br />
        &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<br />
        &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; &nbsp;
        
        &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
        <asp:Button ID="ButtonLogin" runat="server" Text="Log In" OnClick="ButtonLogin_Click" Width="104px" />
        &nbsp;&nbsp;&nbsp;
        <br />
        <br />
        &nbsp;<asp:Label ID="LabelCookie" runat="server" Text="Username saved successfully" Visible="False"></asp:Label>
        <hr />
        <p class="auto-style3">
            <asp:Button ID="ButtonHome" runat="server" OnClick="ButtonHome_Click" Text="Home" Width="118px" />
            &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
            <asp:Button ID="ButtonRegister" runat="server" Text="Register" Width="112px" OnClick="ButtonRegister_Click" />
        </p>
    </form>
</body>
</html>




