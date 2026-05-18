using System;
using System.Collections.Generic;
using System.ComponentModel.DataAnnotations;
using System.Linq;
using System.Web;

namespace WebUI.Models.Data
{
    public class Blog
    {
        [Key]
        public int ID { get; set; }
        public byte[] BlogFoto { get; set; }
        public string BlogBaslik { get; set; }
        public string BlogIcerik { get; set; }
        public Nullable<System.DateTime> BlogTarih { get; set; }
        public Nullable<System.DateTime> Tarih { get; set; }
    }
}