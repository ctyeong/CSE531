<%@ Page Language="C#" AutoEventWireup="true" CodeFile="Registration.aspx.cs" Inherits="AuctionSystem.Registration" %>
<%@ Register TagPrefix="header" TagName="HeaderControl" Src="~/HeaderControl.ascx" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <title>Auction System</title>
    <style type="text/css">
        .auto-style1 {
            width: 167px;
        }
    </style>
</head>
<body>
    <header:HeaderControl runat="server" />
    <h3>&nbsp;  Registration:-</h3>
    <form id="form1" runat="server">
        <table id="MyTable" cellpadding="4" runat="server">
            <tr>
                <td class="auto-style1">User Name*:</td>
                <td>&nbsp;<asp:TextBox ID="TextBoxUsername" runat="server" Height="23px" Width="226px" />
                </td>
            </tr>
            <tr>
                <td class="auto-style1">E-Mail:</td>
                <td>&nbsp;<asp:TextBox ID="TextBoxEmail" runat="server" Width="226px"></asp:TextBox>
                </td>
            </tr>
            <tr>
                <td class="auto-style1">Password*:</td>
                <td>&nbsp;<asp:TextBox ID="TextBoxPassword" TextMode="password" runat="server" Width="227px" Style="margin-left: 0px"></asp:TextBox>
                </td>
            </tr>
            <tr>
                <td class="auto-style1">Confirm Password*:</td>
                <td>&nbsp;<asp:TextBox ID="TextBoxConfirmPassword" TextMode="password" runat="server" Width="226px"></asp:TextBox>
                </td>
            </tr>
            <tr>
                <td class="auto-style1">Category:</td>
                <td >
                    <asp:DropDownList ID= "DropDownListCategory" runat="server" Width="226px">
                        <asp:ListItem>Seller</asp:ListItem>
                        <asp:ListItem>Bidder</asp:ListItem>
                    </asp:DropDownList>
                </td>
            </tr>
            <tr>
                <td class="auto-style1">
                    <asp:Button ID="ButtonHome" runat="server" Text="Home" Width="151px" OnClick="ButtonHome_Click" /></td>
                <td>&nbsp;
                    <asp:Button ID="ButtonRegister" runat="server" Text="Register" Width="168px" OnClick="ButtonRegister_Click" /></td>
            </tr>
        </table>
        &nbsp;
        <asp:Label ID="LabelUserAdded" runat="server" Font-Bold="True" Text="LabelUserAdded" Visible="False"></asp:Label>
        <br />
        &nbsp;<asp:Label ID="LabelErrorMessage" runat="server" ForeColor="Red" Text="LabelErrorMessage" Visible="False"></asp:Label>
    </form>
</body>
</html>



