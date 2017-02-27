<%@ Page Language="C#" AutoEventWireup="true" CodeFile="AdminHome.aspx.cs" Inherits="AdminHome" %>
<%@ Register TagPrefix="header" TagName="HeaderControl" Src="~/HeaderControl.ascx" %>
<!DOCTYPE html>
<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <title>Seller Home</title>
    <style type="text/css">
        .auto-style1 {
            width: 191px;
        }
    </style>
</head>
<body>
    <header:HeaderControl runat="server" />
    <div style="background-color:coral">
    <h2 style="text-align: center">Admin Home</h2>   
    </div>
    <form id="form1" runat="server">
        <asp:Label ID="lblLogin" runat="server" CssClass="padleft10" Text="Users" Font-Bold="True" Font-Underline="True" ToolTip="User Information"></asp:Label>
            <br/><br/>
        <asp:GridView ID="GridView1" runat="server" AutoGenerateColumns="False" CellPadding="4" DataSourceID="AdminDataSource_User" ForeColor="#333333" GridLines="None">
            <AlternatingRowStyle BackColor="White" />
            <Columns>
                <asp:BoundField DataField="userName" HeaderText="userName" SortExpression="userName" />
                <asp:BoundField DataField="userRole" HeaderText="userRole" SortExpression="userRole" />
                <asp:CheckBoxField DataField="isAdmin" HeaderText="isAdmin" SortExpression="isAdmin" />
            </Columns>
            <EditRowStyle BackColor="#2461BF" />
            <FooterStyle BackColor="#507CD1" Font-Bold="True" ForeColor="White" />
            <HeaderStyle BackColor="#507CD1" Font-Bold="True" ForeColor="White" />
            <PagerStyle BackColor="#2461BF" ForeColor="White" HorizontalAlign="Center" />
            <RowStyle BackColor="#EFF3FB" />
            <SelectedRowStyle BackColor="#D1DDF1" Font-Bold="True" ForeColor="#333333" />
            <SortedAscendingCellStyle BackColor="#F5F7FB" />
            <SortedAscendingHeaderStyle BackColor="#6D95E1" />
            <SortedDescendingCellStyle BackColor="#E9EBEF" />
            <SortedDescendingHeaderStyle BackColor="#4870BE" />
        </asp:GridView>
        <asp:SqlDataSource ID="AdminDataSource_User" runat="server" ConnectionString="<%$ ConnectionStrings:ConnectionString %>" SelectCommand="SELECT [userName], [userRole], [isAdmin] FROM [User] ORDER BY [userName]"></asp:SqlDataSource>
        <br/><br/>
        <asp:Label ID="Label2" runat="server" CssClass="padleft10" Text="Auction " Font-Bold="True" Font-Underline="True" ToolTip="Auction Information"></asp:Label>
            <br/><br/>
        <asp:GridView ID="GridView2" runat="server" AutoGenerateColumns="False" CellPadding="4" DataSourceID="AdminDataSource_Bid" ForeColor="#333333" GridLines="None">
            <AlternatingRowStyle BackColor="White" />
            <Columns>
                <asp:BoundField DataField="ownerName" HeaderText="ownerName" SortExpression="ownerName" />
                <asp:BoundField DataField="title" HeaderText="title" SortExpression="title" />
                <asp:BoundField DataField="basePrice" HeaderText="basePrice" SortExpression="basePrice" />
                <asp:BoundField DataField="startingDate" HeaderText="startingDate" SortExpression="startingDate" />
                <asp:BoundField DataField="endingDate" HeaderText="endingDate" SortExpression="endingDate" />
            </Columns>
            <EditRowStyle BackColor="#2461BF" />
            <FooterStyle BackColor="#507CD1" Font-Bold="True" ForeColor="White" />
            <HeaderStyle BackColor="#507CD1" Font-Bold="True" ForeColor="White" />
            <PagerStyle BackColor="#2461BF" ForeColor="White" HorizontalAlign="Center" />
            <RowStyle BackColor="#EFF3FB" />
            <SelectedRowStyle BackColor="#D1DDF1" Font-Bold="True" ForeColor="#333333" />
            <SortedAscendingCellStyle BackColor="#F5F7FB" />
            <SortedAscendingHeaderStyle BackColor="#6D95E1" />
            <SortedDescendingCellStyle BackColor="#E9EBEF" />
            <SortedDescendingHeaderStyle BackColor="#4870BE" />
        </asp:GridView>
        <asp:SqlDataSource ID="AdminDataSource_Bid" runat="server" ConnectionString="<%$ ConnectionStrings:ConnectionString %>" SelectCommand="SELECT [ownerName], [title], [basePrice], [startingDate], [endingDate] FROM [Auctions] ORDER BY [endingDate] DESC"></asp:SqlDataSource>

    </form>
</body>
</html>
