using System;
using System.Collections.Generic;
using System.ComponentModel.DataAnnotations;
using System.Linq;
using System.Web;

namespace WebUI.Models.Data
{
    public class Referans
    {
        [Key]
        public int ID { get; set; }
        public byte[] ReferansFoto { get; set; }
        public string ReferansBaslik { get; set; }
        public string ReferansIcerik { get; set; }
        public Nullable<System.DateTime> ReferansTarih { get; set; }
        public Nullable<System.DateTime> Tarih { get; set; }
    }
}