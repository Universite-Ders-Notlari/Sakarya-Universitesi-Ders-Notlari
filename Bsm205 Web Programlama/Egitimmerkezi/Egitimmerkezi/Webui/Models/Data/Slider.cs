using System;
using System.Collections.Generic;
using System.ComponentModel.DataAnnotations;
using System.Linq;
using System.Web;

namespace WebUI.Models.Data
{
    public class Slider
    {
        [Key]
        public int ID { get; set; }
        public byte[] SliderFoto { get; set; }
        public string SliderText { get; set; }
        public Nullable<System.DateTime> BaslangicTarih { get; set; }
        public Nullable<System.DateTime> BitisTarih { get; set; }
    }
}