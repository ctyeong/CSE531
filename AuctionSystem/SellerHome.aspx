<%@ Page Language="C#" AutoEventWireup="true" CodeFile="SellerHome.aspx.cs" Inherits="AuctionSystem.SellerHome" %>
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
    <h2 style="text-align: center">Seller Home</h2>
    </div>
    <form id="form1" runat="server">
        <div>
            <asp:Label ID="lblLogin" runat="server" CssClass="padleft10" Text="Item Information" Font-Bold="True" Font-Underline="True" ToolTip="Item Information"></asp:Label>
            <br/><br/>
        </div>
        <div>
            <div >
                <table style="padding:1px;border-spacing:0px;width: 50%">
                    <tr>
                        <td>
                            Category
                        </td>
                        <td>
                            <asp:DropDownList ID="catDropDownList" runat="server" DataSourceID="SqlDataSource1" DataTextField="Name"
                                DataValueField="categoryID" Width="165px">
                            </asp:DropDownList>
                            <asp:SqlDataSource ID="SqlDataSource1" runat="server" ConnectionString="<%$ ConnectionStrings:ConnectionString %>" SelectCommand="SELECT [Name], [categoryID] FROM [Categories] ORDER BY [Name]"></asp:SqlDataSource>
                        </td>
                    </tr>
                    <tr>
                        <td >
                            Auction Title
                        </td>
                        <td>
                            <asp:TextBox ID="tboxAuctionTitle" runat="server" Width="250px"></asp:TextBox>
                            <%--<asp:RequiredFieldValidator ID="RequiredFieldValidator1" runat="server" 
                                ControlToValidate="tboxAuctionTitle" ErrorMessage="Auction Title is Required">*</asp:RequiredFieldValidator>--%>
                        </td>
                    </tr>                    
                    <tr>
                        <td>
                            Condition
                        </td>
                        <td>
                            <asp:DropDownList ID="statusDropDownList" runat="server" Width="165px" >
                                <asp:ListItem>New</asp:ListItem>
                                <asp:ListItem>Excellent</asp:ListItem>
                                <asp:ListItem>Good</asp:ListItem>
                                <asp:ListItem>Fair</asp:ListItem>
                                <asp:ListItem>Poor</asp:ListItem>
                                <asp:ListItem>Non-Working</asp:ListItem>
                            </asp:DropDownList>
                            <%--<asp:SqlDataSource ID="SqlDataSourceCond" runat="server" ConnectionString="<%$ ConnectionStrings:ConnectionString %>" SelectCommand="SELECT [condition] FROM [Auctions] ORDER BY [condition]"></asp:SqlDataSource>--%>
                        </td>
                    </tr>
                </table>
            </div>
        </div>
        <div >
        </div>
    <div >
        <div >
        </div>
        <div >
            <br/><br/>
            <asp:Label ID="lblPricing" runat="server" CssClass="padleft10" Text="Pricing Info" Font-Bold="True" Font-Underline="True" ToolTip="Pricing Information"></asp:Label>
            <br/><br/>
        </div>
        <div >
            <div >
                <table style="padding:1px;word-spacing:0px;width: 100%">
                    <tr>
                        <td class="auto-style1">
                            Starting Price
                        </td>
                        <td>
                            <asp:TextBox ID="tboxBasePrice" runat="server" Width="100px" ></asp:TextBox>
                           <%-- $<asp:RequiredFieldValidator ID="RequiredFieldValidator3" runat="server" 
                                ControlToValidate="tboxBasePrice" ErrorMessage="Base Price Is Required">*</asp:RequiredFieldValidator>--%>
                        </td>
                    </tr>                                       
                    <tr>
                        <td class="auto-style1">
                            Start Date
                        </td>
                        <td>
                            <asp:TextBox ID="startDate" runat="server"></asp:TextBox>
                            <asp:Button ID="btnStart" runat="server" Height="22px" Text="Select Start Date" OnClick="btnStart_Click" Width="115px" />
                            <asp:Calendar ID="startCal" runat="server" Visible="False" OnSelectionChanged="startCal_SelectionChanged" OnDayRender="startCal_DayRender" BackColor="White" BorderColor="#999999" CellPadding="4" DayNameFormat="Shortest" Font-Names="Verdana" Font-Size="8pt" ForeColor="Black" Height="180px" Width="200px">
                                <DayHeaderStyle BackColor="#CCCCCC" Font-Bold="True" Font-Size="7pt" />
                                <NextPrevStyle VerticalAlign="Bottom" />
                                <OtherMonthDayStyle ForeColor="#808080" />
                                <SelectedDayStyle BackColor="#666666" Font-Bold="True" ForeColor="White" />
                                <SelectorStyle BackColor="#CCCCCC" />
                                <TitleStyle BackColor="#999999" BorderColor="Black" Font-Bold="True" />
                                <TodayDayStyle BackColor="#CCCCCC" ForeColor="Black" />
                                <WeekendDayStyle BackColor="#FFFFCC" />
                            </asp:Calendar>
                        </td>
                    </tr>                                       
                    <tr>
                        <td class="auto-style1">
                            End Date
                        </td>
                        <td>
                            <asp:TextBox ID="endDate" runat="server" ></asp:TextBox>                          
                            <asp:Button ID="btnEnd" runat="server" Height="20px" Text="Select End Date" OnClick="btnEnd_Click" Width="116px" />
                            <asp:Calendar ID="endCal" runat="server" Visible="False" OnSelectionChanged="endCal_SelectionChanged" OnDayRender="endCal_DayRender" BackColor="White" BorderColor="#999999" CellPadding="4" DayNameFormat="Shortest" Font-Names="Verdana" Font-Size="8pt" ForeColor="Black" Height="180px" Width="200px">
                                <DayHeaderStyle BackColor="#CCCCCC" Font-Bold="True" Font-Size="7pt" />
                                <NextPrevStyle VerticalAlign="Bottom" />
                                <OtherMonthDayStyle ForeColor="#808080" />
                                <SelectedDayStyle BackColor="#666666" Font-Bold="True" ForeColor="White" />
                                <SelectorStyle BackColor="#CCCCCC" />
                                <TitleStyle BackColor="#999999" BorderColor="Black" Font-Bold="True" />
                                <TodayDayStyle BackColor="#CCCCCC" ForeColor="Black" />
                                <WeekendDayStyle BackColor="#FFFFCC" />
                            </asp:Calendar>
                        </td>
                    </tr>                                       
                </table>
            </div>
        </div>
    </div>
    <div >
        <br/><br/>
        <div >
            <asp:Label ID="lblItemDescription" runat="server" CssClass="padleft10" Text="Item Description" Font-Bold="True" Font-Underline="True" ToolTip="Item Details Here"></asp:Label>
            <br/><br/>
        </div>
        <div >
            <div >
                <table style="padding:1px;word-spacing:0px;width: 100%">
                    <tr>
                        <td>
                            <asp:TextBox ID="txtDescription" runat="server" TextMode="MultiLine" Height="100px"
                                Width="520px" />
                            <%--<asp:RequiredFieldValidator ID="txtDescriptionValidator" runat="server" 
                                ControlToValidate="txtDescription" ErrorMessage="Item description is required">*</asp:RequiredFieldValidator>--%>
                        </td>
                    </tr>
                </table>
            </div>
        </div>
        <div >
        </div>
    </div>
        <div >
        <div >
        </div>
        <%--<div >
            <asp:Label ID="lblImage" runat="server" CssClass="padleft10" Text="Images"></asp:Label>
        </div>
        <div >
            <div >
                <table style="padding:1px;word-spacing:0px;width: 100%">
                    <tr>
                        <td>
                            <asp:FileUpload ID="imgUpload1" runat="server" />
                            (thumbnail)<asp:RequiredFieldValidator ID="imgUpload1Validator" 
                                runat="server" ControlToValidate="imgUpload1" 
                                ErrorMessage="Thumbnail image is required">*</asp:RequiredFieldValidator>
                        </td>
                    </tr>
                    
                </table>
            </div>
        </div>
        --%>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
            <asp:Button ID="btnSave" runat="server" Text="Save" Height="45px" Width="75px" OnClick="btnSave_Click" />
        &nbsp;</div>
        <p>
            <asp:Label ID="lblSave" runat="server" ForeColor="Red" Visible="false" Text="Label" Width ="100"></asp:Label>
        </p>
        </form>
        </body>        
    </html>
