using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;
using System.Data.SqlClient;
using System.Configuration;

namespace AuctionSystem
{
    public partial class SellerHome : System.Web.UI.Page
    {
        protected void Page_Load(object sender, EventArgs e)
        {

        }

        protected void btnSave_Click(object sender, EventArgs e)
        {
            SqlConnection conn = new SqlConnection(ConfigurationManager.ConnectionStrings["ConnectionString"].ConnectionString);
            string query1 = "INSERT INTO [Auctions] ([ownerName],[title],[description],[basePrice],[condition],[startingDate],[endingDate],[categoryID]) values (@owner,@title,@description,@basePrice,@condition,@startDate,@endDate,@category);";
            SqlCommand cmdInsertAuction = new SqlCommand(query1, conn);
            cmdInsertAuction.Parameters.Add("@owner", System.Data.SqlDbType.NVarChar).Value = Session["username"].ToString();
            cmdInsertAuction.Parameters.Add("@title", System.Data.SqlDbType.VarChar, 50).Value = tboxAuctionTitle.Text;
            cmdInsertAuction.Parameters.Add("@description", System.Data.SqlDbType.NText, 256).Value = txtDescription.Text;
            cmdInsertAuction.Parameters.Add("@basePrice", System.Data.SqlDbType.Money).Value = tboxBasePrice.Text;
            cmdInsertAuction.Parameters.Add("@condition", System.Data.SqlDbType.NText, 256).Value = statusDropDownList.SelectedValue;
            cmdInsertAuction.Parameters.Add("@startDate", System.Data.SqlDbType.Date).Value = DateTime.Parse(startDate.Text);
            cmdInsertAuction.Parameters.Add("@endDate", System.Data.SqlDbType.Date).Value = DateTime.Parse(endDate.Text);
            cmdInsertAuction.Parameters.Add("@category", System.Data.SqlDbType.Int).Value = catDropDownList.SelectedValue;
            conn.Open();
            cmdInsertAuction.CommandType = System.Data.CommandType.Text;
            Boolean success = false;
            int modified = 0;
            try
            {
                modified = cmdInsertAuction.ExecuteNonQuery();
                success = true;
            }
            catch (Exception e1)
            {

            }
            finally
            {
                conn.Close();
                if (modified > 0 && success)
                {
                    lblSave.Text = "Item Added Successfully";
                    lblSave.Visible = true;
                }
                else
                {
                    lblSave.Text = "Item Could not be added";
                }
            }            
        }

        protected void btnStart_Click(object sender, EventArgs e)
        {
            startCal.Visible = true;
        }

        protected void btnEnd_Click(object sender, EventArgs e)
        {
            endCal.Visible = true;
        }

        protected void startCal_SelectionChanged(object sender, EventArgs e)
        {
            startDate.Text = startCal.SelectedDate.ToShortDateString();
            startCal.Visible = false;
        }

        protected void endCal_SelectionChanged(object sender, EventArgs e)
        {
            endDate.Text = endCal.SelectedDate.ToShortDateString();
            endCal.Visible = false;
        }
        protected void startCal_DayRender(object sender, DayRenderEventArgs e)
        {
            if (e.Day.Date < DateTime.Today)
            {
                e.Day.IsSelectable = false;
                e.Cell.BackColor = System.Drawing.Color.DimGray;
                e.Cell.BorderColor = System.Drawing.Color.Gray;
                e.Cell.ForeColor = System.Drawing.Color.Gray;
            }
        }
        protected void endCal_DayRender(object sender, DayRenderEventArgs e)
        {
            if (e.Day.Date < startCal.SelectedDate)
            {
                e.Day.IsSelectable = false;
                e.Cell.BackColor = System.Drawing.Color.DimGray;
                e.Cell.BorderColor = System.Drawing.Color.Gray;
                e.Cell.ForeColor = System.Drawing.Color.Gray;
            }
        }
    }
}

