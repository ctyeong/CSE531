using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;
using System.Data.SqlClient;
using System.Configuration;
using System.Data;
using System.Drawing;


namespace AuctionSystem
{
    public partial class BidderHome : System.Web.UI.Page
    {
        int auctionID = 0;
        decimal basePrice = 0.0M;
        protected void Page_Load(object sender, EventArgs e)
        {

        }
            
        protected void GridView1_SelectedIndexChanged(Object sender, EventArgs e) {
            GridViewRow row = GridView1.SelectedRow;
                if (row.RowIndex == GridView1.SelectedIndex)
                {
                    row.BackColor = ColorTranslator.FromHtml("#A1DCF0");
                    row.ToolTip = string.Empty;
                    basePrice = Convert.ToDecimal(row.Cells[2].Text);
                    lblselected.Text = "selected Item is " + row.Cells[1].Text + ".";
                    auctionID = (int)GridView1.DataKeys[GridView1.SelectedIndex]["auctionID"];                
            }
                else
                {                    
                    row.ToolTip = "Click to select this row.";
                }            
        }

        protected void btnBid_Clicked(object sender, EventArgs e)
        {
            if (basePrice > Convert.ToDecimal(TextBoxBidPrice.Text.ToString()))
            {
                lblMessage.Text = "Please Enter Price Greater Than Base Price";
            }
            else {
                SqlConnection conn = new SqlConnection(ConfigurationManager.ConnectionStrings["ConnectionString"].ConnectionString);
                conn.Open();
                string query = "INSERT INTO [Bids] ([auctionID],[bidderName],[bidBaseAmount],[bidFinalAmount]) VALUES (@auctionID,@biddername,@basePrice,@bidPrice);";
                SqlCommand cmd = new SqlCommand(query, conn);
                cmd.Parameters.Add("@auctionID", SqlDbType.Int).Value = auctionID;
                cmd.Parameters.Add("@biddername", SqlDbType.NVarChar).Value = Session["username"].ToString();
                cmd.Parameters.Add("@basePrice", SqlDbType.Money).Value = basePrice;
                cmd.Parameters.Add("@bidPrice", SqlDbType.Money).Value = Convert.ToDecimal(TextBoxBidPrice.Text.ToString());
                try
                {
                    int modified = (int)cmd.ExecuteNonQuery();
                    if (modified > 0)
                    {
                        lblMessage.Visible = true;
                        lblMessage.Text = "Bid Successfully Submitted";
                    }
                }
                catch (Exception)
                {
                    lblMessage.Visible = true;
                    lblMessage.Text = "Bid Unsuccessful";
                }
                finally
                {
                    conn.Close();
                }
            }            
        }
    }
}

