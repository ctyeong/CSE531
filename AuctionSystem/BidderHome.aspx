<%@ Page Language="C#" AutoEventWireup="true" CodeFile="BidderHome.aspx.cs" Inherits="AuctionSystem.BidderHome" %>
<%@ Register TagPrefix="header" TagName="HeaderControl" Src="~/HeaderControl.ascx" %>

<!DOCTYPE html>
<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <title>Seller Home</title>
    <style type="text/css">
        .auto-style1 {
            height: 210px;
            width: 838px;
        }
    </style>
    <style type="text/css">
        .hiddencol
        {
           display: none;
        }
</style>
    </head>
<body>
    <header:HeaderControl runat="server" />
    <div style="background-color:coral">
    <h2 style="text-align: center">Bidder Home</h2>
    </div>
    <form id="form1" runat="server" class="auto-style1">
        <asp:GridView ID="GridView1" runat="server" AllowSorting="True" AutoGenerateColumns="False" CellPadding="4" DataSourceID="BidDataSource" Height="16px" OnSelectedIndexChanged="GridView1_SelectedIndexChanged" Width="789px" AutoGenerateSelectButton="True" DataKeyNames = "auctionID" ForeColor="#333333" GridLines="None">
            <AlternatingRowStyle BackColor="White" />
            <Columns>
                <asp:BoundField DataField="title" HeaderText="title" SortExpression="title" />
                <asp:BoundField DataField="basePrice" HeaderText="basePrice" SortExpression="basePrice" />
                <asp:BoundField DataField="condition" HeaderText="condition" SortExpression="condition" />
                <asp:BoundField DataField="Name" HeaderText="Name" SortExpression="Name" />
                <asp:BoundField DataField="description" HeaderText="description" SortExpression="description" />
                <asp:BoundField DataField="auctionID" HeaderText="auctionID" ReadOnly="True" SortExpression="auctionID" ItemStyle-CssClass="hiddencol" HeaderStyle-CssClass="hiddencol">
<HeaderStyle CssClass="hiddencol"></HeaderStyle>

<ItemStyle CssClass="hiddencol"></ItemStyle>
                </asp:BoundField>
            </Columns>
            <EditRowStyle BackColor="#2461BF" />
            <FooterStyle BackColor="#507CD1" ForeColor="White" Font-Bold="True" />
            <HeaderStyle BackColor="#507CD1" Font-Bold="True" ForeColor="White" />
            <PagerStyle ForeColor="White" HorizontalAlign="Center" BackColor="#2461BF" />
            <RowStyle BackColor="#EFF3FB" />
            <SelectedRowStyle BackColor="#D1DDF1" Font-Bold="True" ForeColor="#333333" />
            <SortedAscendingCellStyle BackColor="#F5F7FB" />
            <SortedAscendingHeaderStyle BackColor="#6D95E1" />
            <SortedDescendingCellStyle BackColor="#E9EBEF" />
            <SortedDescendingHeaderStyle BackColor="#4870BE" />
        </asp:GridView>
        <asp:SqlDataSource ID="BidDataSource" runat="server" ConnectionString="<%$ ConnectionStrings:ConnectionString %>" SelectCommand="SELECT [dbo].[Auctions].title,[dbo].[Auctions].basePrice,[dbo].[Auctions].condition,[dbo].[Categories].Name,[dbo].[Auctions].description,[dbo].[Auctions].auctionID
FROM[dbo].[Auctions] INNER JOIN[dbo].[Categories] 
ON[dbo].[Auctions].categoryID = [dbo].[Categories].categoryID 
WHERE[dbo].[Auctions].endingDate &gt;= GETDATE();"></asp:SqlDataSource>
        <br /><br />
        &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
        <asp:Label ID="lblselected" runat="server" Text=""></asp:Label>
        <br /><br />
            &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
            Bidding Price&nbsp;&nbsp;&nbsp<asp:TextBox ID="TextBoxBidPrice" runat="server"></asp:TextBox>            
            &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;            
            <asp:Button ID="btnBid" runat="server" Text="Bid" OnClick="btnBid_Clicked" Width="102px"/>        
        <br/><br/>
        &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<asp:Label ID="lblMessage" runat="server" Text="" Visible="false"></asp:Label>
    </form>
</body>        
</html>
